function [] = TestcontrolGen_v(tar, time)
% sync. the test cases execution in the TDG using minimal combination tech.
% generate one indepent Test control block in the 'tar'
iTestC = [tar '/variant dependent  Test Control'];
iTestC_1 = [tar '/variant dependent  Test Control' '/variant dependent  Test Control'];

if isempty(find_system(tar, 'regexp', 'on','Name','variant dependent  Test Control'))==1
    add_block(['MIL_Test/Test Control/Test Control Architecture/' sprintf('variant dependent \nTest Control')], iTestC);
else
    disp('error: destination exists: variant dependent  Test Control');
    delete_block(find_system(tar, 'regexp', 'on','Name','variant dependent  Test Control'));
    add_block(['MIL_Test/Test Control/Test Control Architecture/' sprintf('variant dependent \nTest Control')], iTestC);
end
set_param(iTestC, 'LinkStatus', 'none');
fix_pos([tar '/TestData 1'], iTestC, 0, 70);
% before connect the test control with testdata, check if the inport free
testdata = get_param([tar '/TestData 1'], 'Linehandles');
if testdata.Inport(1)== -1
    add_line(tar,['variant dependent  Test Control' '/' num2str(1)],['TestData 1/' num2str(1)],'autorouting','on');
else
    delete_line(testdata.Inport(1));
    add_line(tar,['variant dependent  Test Control' '/' num2str(1)],['TestData 1/' num2str(1)],'autorouting','on');
end
ReqNr = length(find_system([tar '/Validation Functions'], 'regexp', 'on','LookUnderMasks','all','Name','Test Info'));
rt = sfroot;
m = rt.find('-isa', 'Stateflow.State','Name','TestCase1');
for i = 1:length(m)
    p = m(i).Path;
    if strcmp(p, iTestC_1) == 1
        parent = m(i).Chart;
        son = m(i);
        break;
    end
end
if ReqNr>1 % add state
    stop_state = son;
    tran = parent.find('-isa', 'Stateflow.Transition','Source',son);
    tran.delete;
    tran_1 = parent.find('-isa', 'Stateflow.Transition','Destination',son);
    tran_1(2).delete;
    junc = parent.find('-isa', 'Stateflow.Junction');
    junc.delete;
    sA1 = son;
    for i = 2:ReqNr
        sA = Stateflow.State(parent);
        sA.Name = ['TestCase' num2str(i)];
        sA.LabelString = ['TestCase' num2str(i) sprintf('\n') 'entry: TestCase = ' num2str(i) ';'];
        Position = son.Position;
        sA.Position = Position;
        sA.Position(2) = Position(2)+70*i;
        tA1A2 = Stateflow.Transition(parent);
        tA1A2.LabelString = ['after(' num2str(time(i-1)) ', tick)'];
        tA1A2.Source = sA1;
        tA1A2.Destination = sA;
        tA1A2.SourceOClock = 6.;
        tA1A2.DestinationOClock = 0.;
        sA1 = sA;
        if i == ReqNr
            
            tA1A2 = Stateflow.Transition(parent);
            tA1A2.LabelString = ['after(' num2str(time(i)) ', tick)' sprintf('\n') '{variant=variant+' num2str(1) ';}'];
            tA1A2.Source = sA1;
            tA1A2.Destination = stop_state;
            tA1A2.SourceOClock = 9.;
            tA1A2.DestinationOClock = 9.;
        end
    end
    

    
elseif ReqNr==0
    disp('There is no Requirement in the VFs!');
end

