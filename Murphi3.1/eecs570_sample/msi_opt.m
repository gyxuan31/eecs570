----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  ProcCount: 3;          -- number of processors
  ValueCount: 3;         -- number of data values
  VC0: 0;                -- low priority virtual channel
  VC1: 1;                -- high priority virtual channel
  VC2: 2;
  QMax: 2;               -- maximum queue size
  NumVCs: VC2 - VC0 + 1;
  NetMax: ProcCount + 3;

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);
  Value: scalarset(ValueCount);
  Home: enum { HomeType };
  Node: union { Home, Proc };
  Sum: 0..ProcCount+1;
  VCType: VC0..NumVCs-1;
  
  MessageType: enum { GetS, GetM, PutS, PutM, PutE,--Caches
                      FwdGetS, FwdGetM, PutAck, --Dir
                      Inv, InvAck, Data, ExData,
                      Downgrade, DgdAck };
  Count: -3..3;


  Message:
    Record
      mtype: MessageType;
      src: Node;
      vc: VCType;
      val: Value;
      cnt: Count;
    End;

  HomeState:
    Record
      state: enum { H_M, H_S, H_I, H_SD, H_E};
      owner: Node;
      sharers: multiset [ProcCount] of Node;
      val: Value;
    End;
  
  ProcState:
    Record
      state: enum { P_M, P_S, P_I, P_ISD, P_IMAD, P_IMA, P_SMAD, P_SMA, P_MIA, P_SIA, P_IIA,
                    P_E, P_EIA};
      val: Value;
      cnt: Count;
    End;

----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
  HomeNode: HomeState;
  Procs: array [Proc] of ProcState;
  Net: array [Node] of multiset [NetMax] of Message;
  InBox: array [Node] of array [VCType] of Message;
  msg_processed: boolean;
  LastWrite: Value;

----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure Send(mtype: MessageType; dst: Node; src: Node; vc: VCType; val: Value; cnt: Count;);
var msg: Message;
Begin
  Assert (MultiSetCount(i: Net[dst], true) < NetMax) "Too many messages";
  msg.mtype := mtype;
  msg.src   := src;
  msg.vc    := vc;
  msg.val   := val;
  msg.cnt   := cnt;
  MultiSetAdd(msg, Net[dst]);
End;

Procedure ErrorUnhandledMsg(msg:Message; n:Node);
Begin
  error "Unhandled message type!";
End;

Procedure ErrorUnhandledState();
Begin
  error "Unhandled state!";
End;

Procedure AddToSharersList(n:Node);
Begin
  if MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) = 0
  then
    MultiSetAdd(n, HomeNode.sharers);
  endif;
End;

Function IsSharer(n:Node) : Boolean;
Begin
  return MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) > 0
End;

Procedure RemoveFromSharersList(n:Node);
Begin
  MultiSetRemovePred(i:HomeNode.sharers, HomeNode.sharers[i] = n);
End;

Function CountSharer() : Sum;
var Total: Sum;
Begin
  Total := 0;
  for n:Node do
    if IsSharer(n) then
        Total := Total +1;
    endif;
  endfor;
  return Total;
End;
-- Sends a message to all sharers except rqst
Procedure SendInvReqToSharers(rqst:Node);
Begin
  for n:Node do
    if (IsMember(n, Proc) &
        MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) != 0)
    then
      RemoveFromSharersList(n);
      if n != rqst then 
        Send(Inv, n, rqst, VC2, UNDEFINED, MultiSetCount(i:HomeNode.sharers, true));

      endif;
    endif;
  endfor;
End;


Procedure HomeReceive(msg: Message);
var cnt:0..ProcCount;  -- for counting sharers
Begin
  -- Debug output may be helpful:
  -- put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
  -- put " at home -- "; put HomeNode.state;
  -- The line below is not needed in Valid/Invalid protocol.  However, the 
  -- compiler barfs if we put this inside a switch, so it is useful to
  -- pre-calculate the sharer count here
  -- cnt := MultiSetCount(i:HomeNode.sharers, true);
  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;
  cnt :=MultiSetCount(i:HomeNode.sharers, true);

  switch HomeNode.state
  case H_I:
    switch msg.mtype
    case GetS:
      Send(ExData, msg.src, HomeType, VC2, HomeNode.val, 0);
      --AddToSharersList(msg.src);
      HomeNode.owner := msg.src;
      HomeNode.state := H_E;

    case GetM:
      Send(Data, msg.src, HomeType, VC2, HomeNode.val, 0);
      HomeNode.owner := msg.src;
      HomeNode.state := H_M;
    
    case PutS:
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
    
    case PutM:
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);

    case PutE:  
      if (msg.src != HomeNode.owner) then
        Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
      endif;
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case H_S:
    switch msg.mtype
    case Downgrade:

    case GetS:
      AddToSharersList(msg.src);
      Send(Data, msg.src, HomeType, VC2, HomeNode.val, 0);
      -- AddToSharersList(msg.src);

    case GetM:
      -- for n: Proc do
      --   if MultiSetCount(i: HomeNode.sharers, HomeNode.sharers[i] = n) > 0 then
      --     Send(Invalidate, n, HomeType, VC0, UNDEFINED);
      --   endif;
      -- endfor;
      HomeNode.owner := msg.src;
      HomeNode.state := H_M;

      if (IsSharer(msg.src) & cnt = 1) then
        RemoveFromSharersList(msg.src);
        Send(Data, msg.src, HomeType, VC2, HomeNode.val, 0);
      
      else
          if ((!IsSharer(msg.src)) & (cnt != 0)) then
            Send(Data, msg.src, HomeType, VC2, HomeNode.val, cnt);
            SendInvReqToSharers(msg.src);
          else
            Send(Data, msg.src, HomeType, VC2, UNDEFINED, cnt - 1);
            SendInvReqToSharers(msg.src);
          endif;
      endif;


    
    case PutS:
      if (IsSharer(msg.src) & cnt = 1) then
        HomeNode.state :=H_I;
      endif;
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
    
    case PutM:
      if (IsSharer(msg.src) & cnt = 1) then
        HomeNode.state := H_I;
      endif;
      RemoveFromSharersList(msg.src);
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);

	  case PutE:  
      RemoveFromSharersList(msg.src);
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);

      else
       ErrorUnhandledMsg(msg, HomeType);

    endswitch;
  
  case H_SD:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;

    case PutS:
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
    
    case PutM:
      -- if msg.src.state = (P_M | P_MIA) then
      --   ErrorUnhandledMsg();
      -- endif;
      if(msg.src != HomeNode.owner) then
        Send(PutAck,msg.src, HomeType, VC1, UNDEFINED, 0);
        RemoveFromSharersList(msg.src);
      endif;
    
    case PutE:  
      if(msg.src != HomeNode.owner) then
        RemoveFromSharersList(msg.src);
        Send(PutAck, msg.src, HomeType,VC1, UNDEFINED, 0);
      endif;
    
    case Data:
      HomeNode.val := msg.val;
      HomeNode.state := H_S;
    
    endswitch;

  case H_M:
    switch msg.mtype
    case GetS:
      Send(FwdGetS, HomeNode.owner, msg.src, VC2, UNDEFINED, cnt);
      AddToSharersList(HomeNode.owner);
      AddToSharersList(msg.src);
      HomeNode.owner  := UNDEFINED;
      HomeNode.state := H_SD;
    
    case GetM:
      Send(FwdGetM, HomeNode.owner, msg.src, VC2, UNDEFINED, 0);
      HomeNode.owner :=msg.src;
    
    -- case PutSNotLast:
    --   Send(PutAck, msg.src, HomeType, VC0,  UNDEFINED);

    case PutS:
      Send(PutAck, msg.src, HomeType, VC0, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
    
    case PutM:
      if(msg.src = HomeNode.owner) then 
        Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
        HomeNode.owner := UNDEFINED;
        HomeNode.state := H_I;
        HomeNode.val := msg.val;
      else
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED,0);
      endif;
    
    case PutE:  
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
    
    case Downgrade:
      if(msg.src = HomeNode.owner) then
        Send(DgdAck, HomeNode.owner, HomeType, VC1, UNDEFINED, 0);
        AddToSharersList(HomeNode.owner);
        HomeNode.owner := UNDEFINED;
        HomeNode.state := H_SD;
      -- else
      --   ErrorUnhandledMsg(msg, HomeType);
      endif;

    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;
  
	case H_E:
    switch msg.mtype

    case GetS:
      Send(FwdGetS, HomeNode.owner, msg.src, VC2, UNDEFINED, 0);
      AddToSharersList(HomeNode.owner);
      AddToSharersList(msg.src);
      HomeNode.owner := UNDEFINED;
      HomeNode.state := H_SD;

    case GetM:
      Send(FwdGetM, HomeNode.owner, msg.src, VC2, UNDEFINED, 0);
      HomeNode.owner := msg.src;
      HomeNode.state := H_M;

    case PutS:
      Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);

    case PutM:
      if (msg.src = HomeNode.owner) then
        Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
        HomeNode.val := msg.val;
        HomeNode.owner := UNDEFINED;
        HomeNode.state := H_I;

      else
        Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
      endif;

    case Downgrade:
      if(msg.src = HomeNode.owner) then
        Send(DgdAck, HomeNode.owner, HomeType, VC1, UNDEFINED, 0);
        AddToSharersList(HomeNode.owner);
        HomeNode.owner := UNDEFINED;
        HomeNode.state := H_SD;
      else 
        ErrorUnhandledMsg(msg, HomeType);
      endif;


    case PutE:
      if (msg.src = HomeNode.owner) then
        Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
        HomeNode.owner := UNDEFINED;
        HomeNode.val := msg.val;
        HomeNode.state := H_I;
            
      else
        Send(PutAck, msg.src, HomeType, VC1, UNDEFINED, 0);
      endif;
    endswitch;

  endswitch;

End;

Procedure ProcReceive(msg:Message; p:Proc);
Begin
  --  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
  --  put " at proc "; put p; put "\n";

  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  alias ps:Procs[p].state do
  alias pv:Procs[p].val do
  alias pc:Procs[p].cnt do

  switch ps
  case P_I:
    switch msg.mtype
    case Inv:
      Send(InvAck, msg.src, p, VC2, UNDEFINED,0);
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_IIA:
    switch msg.mtype
    case PutS:
      msg_processed := false;
    case PutAck:
      pc := 0;
      ps := P_I;
      pv := UNDEFINED;
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed :=false;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_ISD:
    switch msg.mtype
    case Inv:
      msg_processed := false;

    case Data:
      if msg.src = HomeType then
        ps := P_S;
        pv := msg.val;
      else
        ps := P_S;
        pv := msg.val;
      endif;
    
    case ExData: 
      ps := P_E;
      pv := msg.val;

    case FwdGetS:
  		msg_processed := false;

   	case FwdGetM:
 	  	msg_processed := false;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_IMAD:
    switch msg.mtype
    case FwdGetM:
      msg_processed := false;
    case FwdGetS:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case Data:
      pv := msg.val;
      if (msg.src = HomeType) then
        if (msg.cnt <= 0 | msg.cnt + pc <= 0) then
          pc := 0;
          ps := P_M;
          LastWrite := pv;
        else
          pc := pc+ msg.cnt;
          ps := P_IMA;
        endif
      else
        pc := msg.cnt;
        ps := P_M;
        LastWrite := pv;
      endif
    case InvAck:
      if pc = 1 then
        pc := 0;
        ps := P_M;
        LastWrite := pv;
      else
        pc := pc -1;
      endif
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_IMA:
    switch msg.mtype
    case FwdGetM:
      msg_processed := false;
    case FwdGetS:
      msg_processed := false;
    case InvAck:
      if pc = 1 then
        pc :=0;
        ps := P_M;
        LastWrite :=pv;
      else
        pc := pc -1;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_S:
    switch msg.mtype
    case Inv:
      Send(InvAck, msg.src, p, VC2, UNDEFINED, 0);
      ps := P_I;
      pv := UNDEFINED;
    -- case FwdGetM:

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_SIA:
    switch msg.mtype
    case PutS:
      msg_processed := false;
    case FwdGetS:
      msg_processed := false;
    case Inv:
      Send(InvAck, msg.src, p, VC2, UNDEFINED, 0);
      ps := P_IIA;
      pv :=UNDEFINED;
    case PutAck:
      ps := P_I;
      pv :=UNDEFINED;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_SMAD:
    switch msg.mtype
    case PutS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case FwdGetS:
      msg_processed := false;
    case Inv:
      Send(InvAck, msg.src, p, VC2, UNDEFINED, 0);
      pc := 0;
      pv := UNDEFINED;
      ps := P_IMAD;
    case Data:
      pv := msg.val;
      if msg.src = HomeType then
        if msg.cnt = 0 then
          ps := P_M;
          pc := 0;
        else
          ps := P_SMA;
          pc := pc + msg.cnt;
        endif;
      else
        ps := P_M;
        pc := 0;
        LastWrite := pv;
      endif;
    case InvAck:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_SMA:
    switch msg.mtype
    case PutS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case FwdGetS:
      msg_processed := false;
    case InvAck:
      pc := pc - 1;
      if pc = 0 then
        ps := P_M;
        LastWrite := pv;
      endif;
    case Inv:
      Send(InvAck, msg.src, p, VC2, UNDEFINED, 0);
      ps := P_IMAD;
      pv := UNDEFINED; 
    else 
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_M:
    Send(Downgrade, HomeType, p, VC2, UNDEFINED, 0);
    switch msg.mtype
    case DgdAck:
      ps := P_S;
      Send(Data, HomeType, p, VC2, pv, 0);

    case FwdGetS:
      Send(Data, HomeType, p, VC2, pv, 0);
      Send(Data, msg.src, p, VC2, pv, 0);
      ps := P_S;

    case FwdGetM:
      Send(Data, msg.src, p, VC2, pv, 0);
      ps := P_I;
      pv := UNDEFINED;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_MIA:
    switch msg.mtype
    case PutM:
      msg_processed := false;

    case FwdGetS:
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Data, HomeType, p, VC2, pv, 0);
      ps := P_SIA;

    case FwdGetM:
      Send(Data, msg.src, p, VC2, pv, 0);
      ps :=P_IIA;

    case PutAck:
      pc := 0;
      ps := P_I;
      pv := UNDEFINED;
    endswitch;
  
  case P_E:
    Send(Downgrade, HomeType, p, VC2, UNDEFINED, 0);
    switch msg.mtype
    case DgdAck:
      ps := P_S;
      Send(Data, HomeType, p, VC2, pv, 0);

    case FwdGetS:
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Data, HomeType, p, VC2, pv, 0);
      ps := P_S;

    case FwdGetM:
      Send(Data, msg.src, p, VC2, pv, 0);
      pv := UNDEFINED;
      ps := P_I;

    -- else
    -- ErrorUnhandledMsg(msg, p);
    endswitch;
    
  case P_EIA:
    switch msg.mtype 
    case DgdAck:


    case FwdGetS:
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Data, HomeType, p, VC2, pv, 0);
      ps := P_SIA;

    case FwdGetM:
      Send(Data, msg.src, p, VC2, pv, 0);
      ps := P_IIA;

    case PutAck:
      ps := P_I;
      pv := UNDEFINED;

    else
        ErrorUnhandledMsg(msg, p);
    endswitch;


  else
    ErrorUnhandledState();
  endswitch;
  endalias;
  endalias;
  endalias;
End;
----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- Processor actions (affecting coherency)

ruleset n:Proc Do
  alias p:Procs[n] Do

	ruleset v:Value Do
    rule "read request when P_I"
      (p.state = P_I)
      ==>
      Send(GetS, HomeType, n, VC1, UNDEFINED, 0);
      p.state := P_ISD;
    endrule;

    rule "store new value when P_I"
      (p.state = P_I)
      ==>
      Send(GetM, HomeType, n, VC1, UNDEFINED, 0);
      p.state := P_IMAD;
    endrule;

    rule "store new value when P_S"
      (p.state = P_S)
      ==>
      Send(GetM, HomeType, n, VC1, UNDEFINED, 0);
      p.state := P_SMAD;
    endrule;
    
    rule "store new value when P_E"
      (p.state = P_E)
      ==> 
      p.val := v;
      p.state := P_M;
      LastWrite := v;
    endrule;

    rule "PutS when P_S"
      (p.state = P_S)
      ==>
      Send(PutS, HomeType, n, VC0, UNDEFINED, 0);
      p.state :=P_SIA;
    endrule;

  	rule "store new value when P_M"
      (p.state = P_M)
      ==>
      p.val := v;      
      LastWrite := v;  --We use LastWrite to sanity check that reads receive the value of the last write
  	endrule;

    rule "PutM when P_M"
      (p.state = P_M)
      ==>
      Send(PutM, HomeType, n, VC0, p.val, 0);
      p.state := P_MIA;
    endrule;

    rule "PutE when P_E"  
      (p.state = P_E)
      ==>
      Send(PutE, HomeType, n, VC0, p.val, 0);
      p.state := P_EIA;
    endrule;

    -- rule "Self-Dowgrade when P_M"
    --   (p.state =P_M)
    --   ==>
    --   Send(Downgrade, HomeType, n, VC2, p.val, 0);
    -- endrule;

    -- rule "Self-Dowgrade when P_E"
    --   (p.state =P_E)
    --   ==>
    --   Send(Downgrade, HomeType, n, VC2, p.val, 0);
    -- endrule;
  endruleset;
  endalias;
endruleset;

-- Message delivery rules
ruleset n:Node do
  choose midx:Net[n] do
    alias chan:Net[n] do
    alias msg:chan[midx] do
    alias box:InBox[n] do

		-- Pick a random message in the network and delivier it
    rule "receive-net"
      (msg.vc = VC2) |
      (msg.vc=VC1 & MultiSetCount(m:chan, chan[m].vc=VC2)=0) |
      (msg.vc=VC0 & MultiSetCount(m:chan, chan[m].vc=VC2)=0 & MultiSetCount(m:chan, chan[m].vc=VC1)=0)
      ==>

      if IsMember(n, Home) then
        HomeReceive(msg);
          if msg_processed then
            MultiSetRemove(midx, chan);
          endif;
      else
        ProcReceive(msg, n);
          if msg_processed then
            MultiSetRemove(midx, chan);
          endif;
			endif;

	  
    endrule;
  
    endalias
    endalias;
    endalias;
  endchoose;
endruleset;

	-- Try to deliver a message from a blocked VC; perhaps the node can handle it now
	-- ruleset vc:VCType do
  --   rule "receive-blocked-vc"
	-- 		(! isundefined(InBox[n][vc].mtype))
  --     ==>
  --     if IsMember(n, Home) then
  --       HomeReceive(InBox[n][vc]);
  --     else
  --       ProcReceive(InBox[n][vc], n);
	-- 		endif;

	-- 		if msg_processed
	-- 		then
	-- 			-- Message has been handled, forget it
	--   		undefine InBox[n][vc];
	-- 		endif;
	  
  --   endrule;
  -- endruleset;

----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------
startstate
  For v: Value do
    HomeNode.state := H_I;
    undefine HomeNode.owner;
    HomeNode.val := v;
  endfor;
  LastWrite := HomeNode.val;
  
  for i: Proc do
    Procs[i].state := P_I;
    undefine Procs[i].val;
    Procs[i].cnt := 0;
  endfor;
  
  undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "Invalid implies empty owner"
  HomeNode.state = H_I
    ->
      IsUndefined(HomeNode.owner);

invariant "value in memory matches value of last write, when H_S H_I"
     HomeNode.state = H_I | HomeNode.state = H_S
    ->
			HomeNode.val = LastWrite;

invariant "values in caches P_S P_M state match last write"
  Forall n : Proc Do	
     Procs[n].state = P_S | Procs[n].state = P_M
    ->
			Procs[n].val = LastWrite --LastWrite is updated whenever a new value is created 
	end;
	



-- invariant "value is undefined while invalid"
--   Forall n : Proc Do	
--     Procs[n].state = P_I
--     ->
-- 		IsUndefined(Procs[n].val)
-- 	end;

invariant "modified implies empty sharers list"
    HomeNode.state = H_M
      ->
        MultiSetCount(i:HomeNode.sharers, true) = 0;
  
invariant "Invalid implies empty sharer list"
    HomeNode.state = H_I
      ->
        MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "values in memory matches value of last write, when shared or invalid"
  Forall n : Proc Do	
    HomeNode.state = H_S | HomeNode.state = H_I
      ->
		    HomeNode.val = LastWrite
	end;

invariant "values in shared state match memory"
  Forall n : Proc Do	
    HomeNode.state = H_S & Procs[n].state = P_S
      ->
		    HomeNode.val = Procs[n].val
  end
