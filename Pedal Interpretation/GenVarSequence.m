function [] = GenVarSequence (path, ReqNr)
% Sync. the partitioned variants using stateflow
% a Stateflow is added from the
% MIL Library: Test Data: Feature generation: Generate feature variants:
% TestDataVariantsSequence
%
% design outside connection
t = 250;
add_block(['MIL_Test/Test Data/Feature generation/' sprintf('Generate \nfeature variants') sprintf('/TestDataVariants Sequence')],[path sprintf('/TestDataVariants Sequence')]); 
iTestC = [path sprintf('/TestDataVariants Sequence')];
set_param(iTestC, 'LinkStatus', 'none');
fix_pos([path '/switch'], iTestC, -70, 70);
add_line(path,[sprintf('TestDataVariants Sequence') '/' num2str(1)],['switch/' num2str(1)],'autorouting','on');

% design inside stateflow
rt = sfroot;
m = rt.find('-isa', 'Stateflow.State','Name','TDVariant2');
for i = 1:length(m)
    p = m(i).Path;
    p_name = get_param(p,'parent');
    if strcmp(p_name, path) == 1
        parent = m(i).Chart;
        son = m(i);
        break;
%     else
%         disp('Searching stateflow charts failed');
    end
end
if ReqNr>2 % add state
    start_state = parent.find('-isa', 'Stateflow.State','Name','TDVariant1');
    stop_state = parent.find('-isa', 'Stateflow.State','Name','TDVariant2');
    tran = parent.find('-isa', 'Stateflow.Transition','Source',stop_state);
    tran.delete;
    sA1 = son;
    for i = 3:ReqNr
        sA = Stateflow.State(parent);
        sA.Name = ['TDVariant' num2str(i)];
        sA.LabelString = ['TDVariant' num2str(i) sprintf('\n') 'entry: TDVariant = ' num2str(i) ';'];
        Position = son.Position;
        sA.Position = Position;
        sA.Position(2) = Position(2)+70*i;
        tA1A2 = Stateflow.Transition(parent);
        tA1A2.LabelString = ['after(' num2str(t) ', tick)'];
        tA1A2.Source = sA1;
        tA1A2.Destination = sA;
        tA1A2.SourceOClock = 6.;
        tA1A2.DestinationOClock = 0.;
        sA1 = sA;
        if i == ReqNr
            
            tA1A2 = Stateflow.Transition(parent);
            tA1A2.LabelString = ['after(' num2str(t) ', tick)'];
            tA1A2.Source = sA1;
            tA1A2.Destination = start_state;
            tA1A2.SourceOClock = 9.;
            tA1A2.DestinationOClock = 9.;
        end
    end
    
elseif ReqNr==1 % delete one
%     stop_state = parent.find('-isa', 'Stateflow.State','Name','stop');
%     tran = parent.find('-isa', 'Stateflow.Transition','Destination',stop_state);
%     tran.delete;
%     tran = parent.find('-isa', 'Stateflow.Transition','Destination',son);
%     tran.DestinationOClock = 0.;
%     tran.Destination = stop_state;
%     son.delete;
    disp('There is no need for generating TestDataVariants Sequence!');
elseif ReqNr==0
    disp('There is no need for generating TestDataVariants Sequence!');
end