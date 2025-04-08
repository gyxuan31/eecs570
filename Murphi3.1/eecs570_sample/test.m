----------------------------------------------------------------------
-- Invariants                                                       --
----------------------------------------------------------------------

-- Coherency assertions ----------------------------------------------

invariant "value in memory matches value of last write, when invalid"
  HomeNode.state = H_I 
    ->
			HomeNode.val = LastWrite;
	
invariant "value is undefined while invalid"
  Forall n : Proc Do	
     Procs[n].state = P_I
    ->
			IsUndefined(Procs[n].val)
	end;

invariant "value in memory matches value of last write, when shared"
  HomeNode.state = H_S
    ->
			HomeNode.val = LastWrite;

invariant "values in cache match value of last write, when shared"
  Forall n : Proc Do	
     Procs[n].state = P_S
    ->
			Procs[n].val = LastWrite
	end;

invariant "values in cache match value of last write, when smad"
  Forall n : Proc Do	
     Procs[n].state = P_SMad
    ->
			Procs[n].val = LastWrite
	end;

invariant "values in cache match value of last write, when sma"
  Forall n : Proc Do	
     Procs[n].state = P_SMa
    ->
			Procs[n].val = LastWrite
	end;

invariant "values in cache match value of last write, when modified"
  Forall n : Proc Do	
     Procs[n].state = P_M
    ->
			Procs[n].val = LastWrite
	end;

invariant "values in cache match value of last write, when exclusive"
  Forall n : Proc Do	
     Procs[n].state = P_E
    ->
			Procs[n].val = LastWrite
	end;

-- Correctness assertions --------------------------------------------

invariant "invalid implies empty sharer"
  HomeNode.state = H_I
    ->
			MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "invalid implies empty owner"
  HomeNode.state = H_I
    ->
      IsUndefined(HomeNode.owner);

invariant "shared implies not empty sharer"
  HomeNode.state = H_S
    ->
			MultiSetCount(i:HomeNode.sharers, true) > 0;

invariant "modified implies empty sharer"
  HomeNode.state = H_M
    ->
			M