function [] = TestcontrolGen(tar)
% sync. the test cases execution in the TDG using 'one factor at a time' combination tech.
% generate one indepent Test control block in the 'tar'
iTestC = [tar '/independent  Test Control'];
add_block('MIL_Test/Test Control/Test Control Architecture/independent  Test Control ', iTestC);
set_param(iTestC, 'LinkStatus', 'none');
fix_pos([tar '/TestData 1'], iTestC, 0, 70);
% before connect the test control with testdata, check if the inport free
testdata = get_param([tar '/TestData 1'], 'Linehandles');
if testdata.Inport(1)== -1
    add_line(tar,['independent  Test Control' '/' num2str(1)],['TestData 1/' num2str(1)],'autorouting','on');
else
    delete_line(testdata.Inport(1));
    add_line(tar,['independent  Test Control' '/' num2str(1)],['TestData 1/' num2str(1)],'autorouting','on');
end
ReqNr = length(find_system([tar '/Validation Functions'], 'regexp', 'on','LookUnderMasks','all','Name','Test Info'));
rt = sfroot;
m = rt.find('-isa', 'Stateflow.State','Name','TestCase2');
for i = 1:length(m)
    p = m(i).Path;
    if strcmp(p, iTestC) == 1
        parent = m(i).Chart;
        son = m(i);
        break;
    end
end
if ReqNr>2 % add state
    stop_state = parent.find('-isa', 'Stateflow.State','Name','stop');
    tran = parent.find('-isa', 'Stateflow.Transition','Destination',stop_state);
    tran.delete;
    sA1 = son;
    for i = 3:ReqNr
        sA = Stateflow.State(parent);
        sA.Name = ['TestCase' num2str(i)];
        sA.LabelString = ['TestCase' num2str(i) sprintf('\n') 'entry: TestCase = ' num2str(i) ';'];
        Position = son.Position;
        sA.Position = Position;
        sA.Position(2) = Position(2)+70*i;
        tA1A2 = Stateflow.Transition(parent);
        tA1A2.LabelString = 'after(70, tick)';
        tA1A2.Source = sA1;
        tA1A2.Destination = sA;
        tA1A2.SourceOClock = 6.;
        tA1A2.DestinationOClock = 0.;
        sA1 = sA;
        if i == ReqNr
            Position = sA.Position;
            stop_state.Position = Position;
            stop_state.Position(2) = Position(2)+70;
            tA1A2 = Stateflow.Transition(parent);
            tA1A2.LabelString = 'after(70, tick)';
            tA1A2.Source = sA1;
            tA1A2.Destination = stop_state;
            tA1A2.SourceOClock = 6.;
            tA1A2.DestinationOClock = 0.;
        end
    end
    
elseif ReqNr==1 % delete one
    stop_state = parent.find('-isa', 'Stateflow.State','Name','stop');
    tran = parent.find('-isa', 'Stateflow.Transition','Destination',stop_state);
    tran.delete;
    tran = parent.find('-isa', 'Stateflow.Transition','Destination',son);
    tran.DestinationOClock = 0.;
    tran.Destination = stop_state;
    son.delete;
    
elseif ReqNr==0
    disp('There is no Requirement in the VFs!');
end

