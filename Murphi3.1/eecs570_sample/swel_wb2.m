--SWEL protocol

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  ProcCount: 2;          -- number processors
  ValueCount:  2;        -- number of data values.
  VC0: 0;                -- low priority
  VC1: 1;
  VC2: 2;
  NumVCs: 3;
  NetMax: ProcCount-1;


----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);   -- unordered range of processors
  Value:scalarset(ValueCount); -- arbitrary values for tracking coherence
  L2_cache: enum { L2Type };      -- need enumeration for IsMember calls
  Node: union { L2_cache , Proc };
  --fifo_cnt:0..4;
  Count: -3..3;
  Sum: 0..ProcCount+1;
  VCType: VC0..NumVCs-1;

  MessageType: enum {  ReadReq,      -- obtain block in Shared (read-only) state
                       WriteReq,      -- obtain block in Modified (read-write) state
                       PutS,      -- evict block in Shared state
                       PutL2,
                       Inv,       -- Invalidation
                       Ack,
                       Data
                    };

  Message:
    Record
      mtype: MessageType;
      src: Node;
      -- do not need a destination for verification; the destination is indicated by which array entry in the Net the message is placed
      vc: VCType;
      val: Value;
      ack: Count;
      EL:boolean;   --添加
      --wb:boolean;
    End;

   L2State:
    Record
      state: enum { I, PR, PRW, L2_only, SR, SW }; 								
      shared:boolean;
      written:boolean;
      EL:boolean;                    --Exclusive Level
      val: Value;
    End;

   L1State:
    Record
      --state: enum { I, PR, PRW, L2_only, SR, SW }; 								
      EL:boolean;                    --Exclusive Level
      valid:boolean;
      val: Value;
      wb:boolean;
    End;

---------------------------------------------------------------------
--Variables
----------------------------------------------------------------------
var
  L2:  L2State;
  L1:  array [Proc] of L1State;
  Net: array [0..NetMax+1] of Message;
  NetHead: 0..NetMax; -- 指向队头（下一个要处理的消息）
  NetTail: 0..NetMax; -- 指向下一个可写入的位置

  --InBox: array [Node] of array [VCType] of Message; -- If a message is not processed, it is placed in InBox, blocking that virtual channel
  msg_processed: boolean;
  LastWrite: Value; -- Used to confirm that writes are not lost; this variable would not exist in real hardware
  SumV: Sum;
  Net_cnt:0..NetMax+1;



----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure Send(mtype:MessageType;
	       dst:Node;
	       src:Node;
         vc:VCType;
         val:Value;
         cnt: Count;
         EL: boolean;
         );
var msg:Message;
Begin
  Assert (Net_cnt < NetMax + 1) "Too many messages";
  msg.mtype := mtype;
  msg.src   := src;
  msg.vc    := vc;
  msg.val   := val;
  msg.ack   := cnt;
  msg.EL    := EL;
  Net[NetTail] := msg;
  
  if (NetTail = NetMax) then
    NetTail := 0;
  else
    NetTail := NetTail + 1;
    
  endif;
  Net_cnt := Net_cnt + 1;
End;

-- Sends a message to others except rqst
Procedure Broadcast(rqst:Node;
         mtype:MessageType; 
         vc:VCType;
         val:Value;
        );
Begin
  for n:Node do
    if (IsMember(n, Proc))   
    then
      if (n != rqst & n != L2Type)
      then 
        -- Send invalidation message here
        --Send(mtype,n,rqst,vc,UNDEFINED,ProcCount-1, L2.EL); 
        L1[n].EL := false;
        L1[n].valid := false;
        L1[n].val := UNDEFINED; 
        --send invlidation to all 
      endif;
    endif;
  endfor;
End;

Procedure Broadcast_EL_F(rqst:Node);
Begin
  for n:Node do
    if (IsMember(n, Proc))   
    then
      if ( n != rqst & n != L2Type)
      then 
        -- Send invalidation message here
        --Send(mtype,n,rqst,vc,UNDEFINED,ProcCount-1, L2.EL); 
        L1[n].EL := false;
        --send invlidation to all 
      endif;
    endif;
  endfor;
End;

Procedure Get_L1_Value(rqst:Node);
Begin
  for n:Proc do  
      if ( n != rqst) then 
        if (L1[n].EL = true) then
        -- Send invalidation message here
        --Send(mtype,n,rqst,vc,UNDEFINED,ProcCount-1, L2.EL); 
        L2.val := L1[n].val;

        --send invlidation to all 
      endif;
    endif;
  endfor;
End;

Procedure GrantL1(n: Node; data:Value);     ---set L1's EL true
Begin
  L1[n].EL := true;
  L1[n].valid := true;
  L1[n].val := data;
End;

Procedure GrantL1_Wb (n: Node);     ---set L1's wb true
Begin
  L1[n].wb := true;
End;

Procedure GrantL1_Shared(n: Node; data:Value);     ---set L1's EL false
Begin
  L1[n].EL := false;
  L1[n].valid := true;
  L1[n].val := data;
End;

Procedure GrantL1_Value(n: Node; data:Value);     ---set L1's value
Begin
  L1[n].val := data;
End;

Procedure PutL1(n: Proc);     ---set L1's EL false
Begin
  L1[n].EL := false;
  L1[n].valid := false;
  L1[n].val := UNDEFINED;
End;


Procedure PutAllL1();
Begin 
  for n:Proc do
  PutL1(n);
  endfor;
End;
-------------------------------------------------

Procedure ErrorUnhandledMsg(msg:Message; n:Node);
Begin
  error "Unhandled message type!";
End;

-------------------------------------------------

Procedure ErrorUnhandledState();
Begin
  error "Unhandled state!";
End;
-------------------------------------------------

-------------------------------------------------
-- L1 Cache
-------------------------------------------------
-- Procedure L1Receive(msg:Message; p:Proc);
-- Begin
--   put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--   put " at proc "; put p; put "\n";
--   switch msg.mtype
    -- case Data:
    --   L1[p].val := msg.val;
      -- L1[p].valid := true;
      -- L1[p].EL := true;
      -- switch L2.state
      --   case SW:
      --     L1[p].valid := false; -- valid: L1 private / share
      --     L1[p].EL := false;
      --   case PRW:
      --     L1[p].valid := true; -- valid: L1 private / share
      --     L1[p].EL := true;
      --     endif;
      --   else
      --     L1[p].valid := true; -- valid: L1 private / share
      --     if !msg.EL & !L2.shared then 
      --       L1[p].EL := true;
      --   endif;
      -- endswitch;

--     case Inv:
--       L1[p].EL := false;
--       L1[p].val := UNDEFINED;
--       L1[p].valid := false;
--   endswitch;
-- end;

-------------------------------------------------
-- L2 Cache
-------------------------------------------------

Procedure L2Receive(msg:Message);
Begin
--   put "Receiving "; put msg.mtype; put " on proc:"; put msg.src; 
--   put " at L2 "; put L2.state; put "\n"; put Net_cnt;
        if (NetHead = NetMax) then
         NetHead := 0;
      else
         NetHead := NetHead + 1;
      endif;     

      Net_cnt := Net_cnt - 1;
  switch L2.state

  case I:
    switch msg.mtype
      case WriteReq:      
        L2.state := PRW;
        L2.written := true;
        L2.shared := false;
        L2.EL := false;
        --L2.val := msg.val;
        GrantL1(msg.src,msg.val);
        GrantL1_Wb(msg.src);
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);

      case ReadReq:
        L2.state := PR;
        L2.written := false;
        L2.shared := false;
        L2.EL := false; 
        GrantL1(msg.src,L2.val);
        
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);
      else
        ErrorUnhandledMsg(msg, L2Type);
    endswitch;

  case PR:
    switch msg.mtype
      case WriteReq:
        if (msg.EL = true) then
          L2.written := true;
          --L2.shared := false;
          L2.state := PRW;
          L2.EL := false;
          --L2.val := msg.val;
          GrantL1_Wb(msg.src);
          GrantL1_Value(msg.src,msg.val);
        else 
          Broadcast(L2Type,Inv,VC2,UNDEFINED); 
          L2.state := SW;
          L2.written := true;
          L2.shared := true;
          L2.EL := true;
          --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);
          L2.val := msg.val;
        endif  
      
      case ReadReq:
        if (msg.EL = true) then
        L2.state := PR;
        --L2.written := false;
        L2.shared := false;
        L2.EL := false;
        else
        L2.state := SR;
        --L2.written := false;
        L2.shared := true;
        L2.EL := false;
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);   
        GrantL1_Shared(msg.src,L2.val);
        Broadcast_EL_F(msg.src);
        endif;

      case PutS:
      if(L1[msg.src].EL = true) then
        L2.state := L2_only;
        L2.EL := true;
        PutL1(msg.src);
 
      endif;

      else
        ErrorUnhandledMsg(msg, L2Type);
    endswitch;


  case PRW:
    switch msg.mtype
      case WriteReq:
        if (msg.EL = true) then
          L2.written := true;
          L2.state := PRW;
          L2.EL := false;
          GrantL1_Value(msg.src,msg.val);
          --L2.val := msg.val;
        else 
          Broadcast(L2Type,Inv,VC2,UNDEFINED);
          L2.state := SW;
          L2.written := true;
          L2.shared := true;
          L2.EL := true;
          --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);
          L2.val := msg.val;
        endif  

      case ReadReq:
        L2.state := SW;
        L2.written := true;
        L2.shared := true;
        L2.EL := true;
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);
        Get_L1_Value(msg.src);
        GrantL1(msg.src,L2.val);
        Broadcast(L2Type,Inv,VC2,UNDEFINED);
        
      case PutS:

        if (L1[msg.src].EL = true) then
        L2.state := L2_only;
        L2.written := true;
        L2.EL := true;
        L2.val := L1[msg.src].val;
        PutL1(msg.src);
        endif;
   
      
      else
        ErrorUnhandledMsg(msg, L2Type);
  endswitch;


  case L2_only:
    switch msg.mtype
      case WriteReq:
        L2.state := PRW;
        L2.written := true;
        L2.EL := false;
        GrantL1_Wb(msg.src);
        --L2.val := msg.val;
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);
        GrantL1(msg.src,msg.val);
        
      case ReadReq:
        L2.state := PR;
        L2.EL := false;
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);
        GrantL1(msg.src,L2.val);      

      case PutS:

      
      else
        ErrorUnhandledMsg(msg, L2Type);
    endswitch;

  case SR:
    switch msg.mtype
      case WriteReq:
        Broadcast(L2Type,Inv,VC2,UNDEFINED);           
        L2.state := SW;
        L2.written := true;
        L2.shared := true;
        L2.EL := true;
        L2.val := msg.val;
        GrantL1_Wb(msg.src);
        -- if (msg.src.EL = false) then
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);
        --endif;

      case ReadReq:
        L2.state := SR;
        --L2.written := false;
        L2.shared := true;
        L2.EL := false;
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);   
        GrantL1_Shared(msg.src,L2.val);

      case PutL2:
        L2.state := I;
        L2.written := false;
        L2.shared := false;
        L2.EL := false;
        --L2.val := UNDEFINED;
        PutAllL1();
      
      case PutS:
      else
        ErrorUnhandledMsg(msg, L2Type);
    endswitch;

  case SW:
    switch msg.mtype
      case WriteReq:    
        L2.state := SW; 
        L2.written := true;
        L2.shared := true;
        L2.EL := true;
        L2.val := msg.val;
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);

      case ReadReq:
        L2.state := SW; 
        L2.written := true;
        L2.shared := true;
        L2.EL := true;
        --Send(Data,msg.src,L2Type,VC2,L2.val,UNDEFINED,L2.EL);   
        --GrantL1(msg.src,L2.val);

      case PutL2:
        L2.state := I;
        L2.written := false;
        L2.shared := false;
        L2.EL := false;
        --L2.val := UNDEFINED;
        PutAllL1();
      
      case PutS:

      else
        ErrorUnhandledMsg(msg, L2Type);
    endswitch;

    else
    ErrorUnhandledState();
  endswitch;
  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
  put " at L2 "; put L2.state; put "\n"; put Net_cnt;
  
End;

function Sumfunc(): Sum;
var total: Sum;
begin
  total := 0 ;
  for n:Proc do
    if L1[n].EL then
      total := total + 1;
    endif;
  endfor;
  if L2.EL then
    total := total +1;
  endif;
  return total;
end;
----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- Processor actions (affecting coherency)

ruleset n:Proc Do
    alias p:L1[n] Do
    alias p2:L2 Do
	    ruleset v:Value Do
	/*ruleset v:Value Do
  	rule "store new value"
   	 (p.state = P_Valid)
    	==>
 		   p.val := v;      
 		   LastWrite := v;  --We use LastWrite to sanity check that reads receive the value of the last write
  	endrule;
	endruleset;*/

    rule "Initial L2 Allocation"
        (p2.state = I & Net_cnt = 0)
    ==>
        Send(WriteReq,L2Type,n,VC0,v,UNDEFINED,p.EL);
        /*Send(ReadReq, HomeType, n, VC0, UNDEFINED);*/
        /*p2.state := L2_only;*/
    endrule;

    rule "Initial Read"
        (p2.state = I & Net_cnt = 0)
    ==>
        Send(ReadReq,L2Type,n,VC0,UNDEFINED,UNDEFINED,p.EL);
        --p.valid := true;
        /*Send(ReadReq, HomeType, n, VC0, UNDEFINED);*/
        /*p2.state := L2_only;*/
    endrule;

    rule "First L1 Read"
        (p2.state = L2_only & p.valid = false & Net_cnt < NetMax + 1)
    ==>
        Send(ReadReq,L2Type,n,VC0,UNDEFINED,UNDEFINED,p.EL);
        --p.valid := true;
    /*Send(ReadReq, HomeType, n, VC0, UNDEFINED);*/
    endrule;

    rule "L1 Eviction"
        (p2.state = PR & p.EL = true & Net_cnt < NetMax + 1)
    ==>
        Send(PutS,L2Type,n,VC0,UNDEFINED,UNDEFINED,p.EL);
        --p.EL := false;
        --p.valid := false;
    endrule;

    rule "First L1 Write"
        (p2.state = L2_only & p.valid = false & Net_cnt < NetMax + 1)
    ==>
        Send(WriteReq,L2Type,n,VC0,v,UNDEFINED,p.EL);
        --p.valid := true;
        --p.val := v;
        /*要不要lastwrite*/
    endrule;

    rule "L1 Eviction PRW"
        (p2.state = PRW & p.EL = true & Net_cnt < NetMax + 1)
    ==>
        Send(PutS,L2Type,n,VC0,UNDEFINED,UNDEFINED,p.EL);
        --p.EL := false;
        --p.valid := false;
    endrule;

    rule "Exclusive L1 Write"
        (p2.state = PR & p.EL = true & Net_cnt < NetMax + 1)
    ==>
        Send(WriteReq,L2Type,n,VC0,v,UNDEFINED,p.EL);
        --p.val := v;
        /*要不要lastwrite*/
    endrule;

    rule "Additional Sharer Read"
        (p2.state = PRW & p.EL = FALSE & p2.EL = FALSE & Net_cnt < NetMax + 1) 
    ==>
        Send(ReadReq,L2Type,n,VC0,UNDEFINED,UNDEFINED,p.EL);
        /*记得L2收到这条消息要判断这个Read/Write Req是不是之前的L1，如果是则不变状态，不是则broadcast一下，让所有L1变成INV，L2 S置1*/
    endrule;

    rule "Additional Sharer Write"
        (p2.state = PRW & p.EL = FALSE & p2.EL = FALSE & Net_cnt < NetMax + 1) 
    ==>
        Send(WriteReq,L2Type,n,VC0,v,UNDEFINED,p.EL);
        --p2.val = v;
        /*记得L2收到这条消息要判断这个Read/Write Req是不是之前的L1，如果是则不变状态，不是则broadcast一下，让所有L1变成INV，L2 S置1*/
    endrule;

    rule "Other L1 Write"
        (p2.state = PR & p.EL = FALSE & p2.EL = FALSE & Net_cnt < NetMax + 1) 
    ==>
        Send(WriteReq,L2Type,n,VC0,v,UNDEFINED,p.EL);
        --p2.val = v;
        /*记得L2收到这条消息要判断这个Write Req是不是之前的L1，如果是则go to PRW，不是则broadcast一下，让所有L1变成INV，L2 S置1*/
    endrule;

    rule "Any Write"
        (p2.state = SR & p.EL = FALSE & p2.EL = FALSE & Net_cnt < NetMax + 1) 
    ==>
        Send(WriteReq,L2Type,n,VC0,v,UNDEFINED,p.EL);
        --p2.val = v;
        
    endrule;

    
    rule "Additional Sharer Read"
        (p2.state = PR & p.EL = FALSE & p2.EL = FALSE & Net_cnt < NetMax + 1) 
    ==>
        Send(ReadReq,L2Type,n,VC0,UNDEFINED,UNDEFINED,p.EL);
        
        /*记得L2收到这条消息要判断这个Read Req是不是之前的L1，如果是则不变状态，不是则L2 S置1*/
    endrule;

    rule "SW Read"
        (p2.state = SW & p.EL = FALSE & p2.EL = TRUE & Net_cnt < NetMax + 1) 
    ==>
        Send(ReadReq,L2Type,n,VC0,UNDEFINED,UNDEFINED,p.EL);
        
        /*记得L2收到这条消息要判断这个Read Req是不是之前的L1，如果是则不变状态，不是则L2 S置1*/
    endrule;

    rule "SW Write"
        (p2.state = SW & p.EL = FALSE & p2.EL = TRUE & Net_cnt < NetMax + 1) 
    ==>
        Send(WriteReq,L2Type,n,VC0,v,UNDEFINED,p.EL);
        
        /*记得L2收到这条消息要判断这个Read Req是不是之前的L1，如果是则不变状态，不是则L2 S置1*/
    endrule;

    -- rule "SW Evict"
    --     ((p2.state = SW | p2.state = SR) & p.EL = FALSE & Net_cnt < NetMax + 1) 
    -- ==>
    --     Send(PutL2,L2Type,n,VC0,UNDEFINED,UNDEFINED,p.EL);
        
    --     /*记得L2收到这条消息要判断这个Read Req是不是之前的L1，如果是则不变状态，不是则L2 S置1*/
    -- endrule;

    endruleset;
    endalias;
    endalias;
endruleset;

-- -- Message delivery rules
ruleset n:Node do
    alias msg: Net[NetHead] do

		-- Pick a random message in the network and delivier it
    rule "receive-net"

		-- NetHead[n] < NetTail[n]
    n = L2Type & Net_cnt > 0

    ==>
        L2Receive(msg); 
        -- put "receive-net @ L2Type triggered\n";
        -- put msg.mtype;
      
 

				

      -- else
      --   L1Receive(msg, n);
      --   --MultiSetRemove(midx, chan);
			--endif;
	    
    endrule;
  
    endalias;
   
  
endruleset;
-- ruleset n:Node do
--   choose midx:Net[n] do
--     alias chan:Net[n] do
--     alias msg:chan[midx] do
--     alias box:InBox[n] do
--     rule "receive-net"
--       IsMember(n, L2_cache)
--       ==>
--         L2Receive(msg); 
--     endrule;
  
--     rule "receive-net"
--       IsMember(n, L2_cache)
--       ==>
--         L2Receive(msg); 
--     endrule;
--     endalias;
--     endalias;
--     endalias;
--   endchoose;
-- endruleset;      


----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------
startstate


  NetHead := 0;
  NetTail := 0;
  Net_cnt := 0;

  for i:0..NetMax-1 do
    undefine Net[i]; -- 清除原有 message 内容
  endfor;

  -- home node initialization
  L2.state := I;  
  L2.shared := false;
  L2.written := false;
  for v:Value do
  L2.val := 1;       -- 随机（枚举）选一个 Value
  endfor;
    --LastWrite := v;
                -- 拿到第一个就退出

  L2.EL := false;

  
  -- processor initialization
  for i:Proc do
    L1[i].EL := false;  
    L1[i].valid := false;
    L1[i].wb := false;  
    undefine L1[i].val;
  endfor;
  -- network initialization
  undefine Net;
  

  endstartstate;
----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "At most zero EL flag is true in the system - 0"
  L2.state = I | L2.state = SR
    ->
      Sumfunc() = 0;

invariant "At most one EL flag is true in the system - 1"
  L2.state = PR | L2.state = PRW | L2.state = L2_only | L2.state = SW
    ->
      Sumfunc() = 1;

invariant "L2_only state consistency"
    forall p: Proc Do
      L2.state = L2_only 
    -> 

      L1[p].valid = false &
      L1[p].EL = false
    end;

invariant "Modified state exclusivity"
      L2.state = SW 
    -> 
    Forall p: Proc Do 
      L1[p].valid = false &
      L1[p].EL = false &
      L2.EL = true
    end;

invariant "Values in L1 match L2 when PR and PRW state"
  forall p:Proc Do
   (L2.state = PR & L1[p].EL= true) --| (L2.state = PRW & L1[p].EL= true)
    ->
   L1[p].val = L2.val
  end;

invariant "Values in L1 match L2 when SR state"
  forall p:Proc Do
   L2.state = SR & L1[p].valid = true
    ->
   L1[p].val = L2.val
  end;

