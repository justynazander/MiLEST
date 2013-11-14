function [TCD, p_nr, vr_max] = Testdata_Preconditions_G(sys,m1,tar,duration_tick,TCD_Previous)
% Preconditions level transformation

TestdataBlock = [tar '/TestData 1/'];
Testdata_block = [tar '/TestData 1'];
%VFsBlock = 'LCTC_vTD8_Transformation4_TC/Validation Functions/';
VFsBlock = [tar '/Validation Functions/'];
Precon = find_system([sys '/' m1], 'SearchDepth',2,'regexp', 'on','LookUnderMasks','all','Name','Activate');
p_nr = 0;
 % the number of the preconditions in this requirement one 'in' one 'out'
% generate the bus creator and bus seletor for better layout
%add_block('Simulink/Signal Routing/Bus Creator',[TestdataBlock m1 '/Bus Creator 2']); % for signal to sequencing of test data

add_block('Simulink/Signal Routing/Bus Creator',[TestdataBlock m1 '/Bus Creator 1']);
fix_pos([TestdataBlock m1 '/<Preconditions name>'],[TestdataBlock m1 '/Bus Creator 1'],20,100*length(Precon));
fix_pos([TestdataBlock m1 '/<Preconditions name>'], [TestdataBlock m1 sprintf('/Sequencing of test data in time\ndue to Preconditions')],125,-100);
%fix_pos([TestdataBlock m1 sprintf('/Sequencing of test data in time\ndue to Preconditions')],[TestdataBlock m1 '/Bus Creator 2'],-100,0);
%add_line([TestdataBlock m1],['Bus Creator 2' '/1'],sprintf('Sequencing of test data in time\ndue to Preconditions/1'),'autorouting','on');
position = get_param([TestdataBlock m1 '/Bus Creator 1'], 'Position');
position(2) = position(2)-length(Precon)*20;
set_param([TestdataBlock m1 '/Bus Creator 1'], 'Position',position);
vr_max = [0];
%===
for j = 1:length(Precon)
    Act = Precon{j};
    ActOut = get_param(Act, 'Blocktype');
    if strcmp(ActOut, 'Outport') == 1
        R_Act = length(Act)-length('/Activate');
        F_Act = length([sys '/' m1 '/'])+1;
        ActName = Act(F_Act:R_Act); % Preconditions Name
        
        add_block('MIL_Test/Test Data/Test Data Architecture/<Test data generator>/<Requirement name>/<Preconditions name>',[TestdataBlock m1 '/' ActName]);
        p_nr = p_nr + 1 ;
        set_param([TestdataBlock m1 '/' ActName], 'LinkStatus', 'none');
        vr_max_1 = TestdataFeature_G([VFsBlock m1 '/' ActName],[TestdataBlock m1 '/' ActName],tar,duration_tick);
        vr_max = [vr_max vr_max_1];
        fix_pos([TestdataBlock m1 '/<Preconditions name>'],[TestdataBlock m1 '/' ActName],-150,j*120+50);
        In = find_system([TestdataBlock m1 '/' ActName], 'SearchDepth',1,'BlockType','Outport');% the name of Input Signal
        for k = 1:length(In)
               v = get_param(In{k},'Name');
               %In{k} = v;
            
            if strcmp(v,'Activate') == 1
                   inports = get_param([TestdataBlock m1 '/Bus Creator 1'],'Linehandles');
                   inports_l = length(inports.Inport);
                   portNr = get_param(In{k},'Port');
                   free_port = 0;
                   for m = 1:inports_l
                       if inports.Inport(m) == -1
                           free_port = 1;
                           line_name = add_line([TestdataBlock m1],[ActName '/1'],['Bus Creator 1' '/' num2str(m)],'autorouting','on');
                           set_param(line_name,'Name',v);
                           break;
                       end
                   end
                   if free_port == 0
                       freeports = str2num(get_param([TestdataBlock m1 '/Bus Creator 1'],'Inputs'))+1;
                       set_param([TestdataBlock m1 '/Bus Creator 1'],'Inputs',num2str(freeports));
                       line_name = add_line([TestdataBlock m1],[ActName '/1'],['Bus Creator 1' '/' num2str(freeports)],'autorouting','on');
                       set_param(line_name,'Name',v);
                   end
%                 line_name = add_line([TestdataBlock m1],[ActName '/1'],['Bus Creator 2' '/1'],'autorouting','on');
%                 set_param(line_name,'Name',v);
            else
%                  freeports = str2num(get_param([TestdataBlock m1 '/PrecAct ' v],'Inputs'))+1;
%                  set_param([TestdataBlock m1 '/PrecAct ' v],'Inputs',num2str(freeports));
%                  portNr = get_param(In{k},'Port');
%                  line_name = add_line([TestdataBlock m1],[ActName '/' portNr],['PrecAct ' v '/' num2str(freeports-1)],'autorouting','on');
%                  set_param(line_name,'Name',v);
%%% for bus creator
                   inports = get_param([TestdataBlock m1 '/Bus Creator 1'],'Linehandles');
                   inports_l = length(inports.Inport);
                   portNr = get_param(In{k},'Port');
                   free_port = 0;
                   for m = 1:inports_l
                       if inports.Inport(m) == -1
                           free_port = 1;
                           line_name = add_line([TestdataBlock m1],[ActName '/' portNr],['Bus Creator 1' '/' num2str(m)],'autorouting','on');
                           set_param(line_name,'Name',v);
                           break;
                       end
                   end
                   if free_port == 0
                       freeports = str2num(get_param([TestdataBlock m1 '/Bus Creator 1'],'Inputs'))+1;
                       set_param([TestdataBlock m1 '/Bus Creator 1'],'Inputs',num2str(freeports));
                       line_name = add_line([TestdataBlock m1],[ActName '/' portNr],['Bus Creator 1' '/' num2str(freeports)],'autorouting','on');
                       set_param(line_name,'Name',v);
                   end
%===
            end
        end
        if length(find_system(([TestdataBlock m1 '/' ActName]),'SearchDepth',1,'Name',sprintf('Out\nBus'))) > 0
               fix_pos([TestdataBlock m1 '/' ActName],[TestdataBlock m1 sprintf('/Out\nBus')],-120,-20);
               add_line([TestdataBlock m1],sprintf('Out\nBus/1'),[ActName '/1'],'autorouting','on');
        end
    end
    
end
% generate bus selector for better layout
In = find_system([TestdataBlock m1], 'SearchDepth',1,'BlockType','Outport');% the name of Input Signal
for k = 1:length(In)
    v = get_param(In{k},'Name');
    add_block('Simulink/Signal Routing/Bus Selector',[TestdataBlock m1 '/Bus Selector ' v]);
    fix_pos([TestdataBlock m1 '/PrecAct ' v],[TestdataBlock m1 '/Bus Selector ' v],-130,-40);
    position = get_param([TestdataBlock m1 '/Bus Selector ' v], 'Position');
    position(2) = position(2)-length(Precon)*6;
    set_param([TestdataBlock m1 '/Bus Selector ' v], 'Position',position);
    add_line([TestdataBlock m1],['Bus Creator 1' '/1'],['Bus Selector ' v '/1'],'autorouting','on');
    insignal = get_param([TestdataBlock m1 '/Bus Selector ' v], 'Inputsignals');
    outsignal = [];
    flag_outsignal = 0; %judge if the Bus Creator includes the inputsignal
    for i = 1:length(insignal)
        q = findstr(insignal{i}, v);
        if isempty(q) == 0
            flag_outsignal = 1;
            outsignal = [outsignal ',' insignal{i}];
        
        end
    end
    if flag_outsignal == 1
        outsignal = outsignal(2:end);
        set_param([TestdataBlock m1 '/Bus Selector ' v], 'Outputsignals', outsignal);
        ph = get_param([TestdataBlock m1 '/Bus Selector ' v],'Porthandles');
    
        for i = 1:length(ph.Outport)
            freeports = str2num(get_param([TestdataBlock m1 '/PrecAct ' v],'Inputs'))+1;
            set_param([TestdataBlock m1 '/PrecAct ' v],'Inputs',num2str(freeports));
            add_line([TestdataBlock m1],['Bus Selector ' v '/' num2str(i)],['PrecAct ' v '/' num2str(freeports-1)],'autorouting','on');
        end
    elseif flag_outsignal == 0
        inline = get_param([TestdataBlock m1 '/Bus Selector ' v], 'Linehandles');
        delete_line(inline.Inport);
        delete_block([TestdataBlock m1 '/Bus Selector ' v]);
    end
    
    
end
add_block('Simulink/Signal Routing/Bus Selector',[TestdataBlock m1 '/Bus Selector Seq']);
fix_pos([TestdataBlock m1 '/' sprintf('Sequencing of test data in time\ndue to Preconditions')],[TestdataBlock m1 '/Bus Selector Seq'],-130,-40);
add_line([TestdataBlock m1],['Bus Creator 1' '/1'],['Bus Selector Seq' '/1'],'autorouting','on');
insignal = get_param([TestdataBlock m1 '/Bus Selector Seq'], 'Inputsignals');
outsignal = [];
flag_outsignal = 0; %judge if the Bus Creator includes the inputsignal
for i = 1:length(insignal)
    q = findstr(insignal{i}, 'Activate');
    if isempty(q) == 0
        flag_outsignal = 1;
        outsignal = [outsignal ',' insignal{i}];

    end
end
if flag_outsignal == 1
    outsignal = outsignal(2:end);
    set_param([TestdataBlock m1 '/Bus Selector Seq'], 'Outputsignals', outsignal);
    ph = get_param([TestdataBlock m1 '/Bus Selector Seq'],'Porthandles');
    state_in_nr = length(ph.Outport);
    for i = 1:length(ph.Outport)
%         freeports = str2num(get_param([TestdataBlock m1 '/PrecAct ' v],'Inputs'))+1;
%         set_param([TestdataBlock m1 '/PrecAct ' v],'Inputs',num2str(freeports));
%         add_line([TestdataBlock m1],['Bus Selector Seq' '/' num2str(i)],['PrecAct ' v '/' num2str(freeports-1)],'autorouting','on');
    end
elseif flag_outsignal == 0
    state_in_nr = 0;
    inline = get_param([TestdataBlock m1 '/Bus Selector Seq'], 'Linehandles');
    delete_line(inline.Inport);
    delete_block([TestdataBlock m1 '/Bus Selector Seq']);
end
%====
% redesign the Requirement level sketch
    % design the Initialisation &\nStabilisation block
    
    delete_block([TestdataBlock m1 '/<Preconditions name>']);
    
    In2 = find_system([TestdataBlock m1], 'SearchDepth',1,'BlockType','Outport');
    Outline_name = get_param([TestdataBlock m1],'Linehandles');
    for i = 1: length(In2)
       
        v = get_param(In2{i},'Name');
        add_block('Simulink/Sources/Constant',[TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/Constant ' num2str(i)]);
        set_param([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/Constant ' num2str(i)],'Value','0');
        fix_pos([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/<Feature generation>'],[TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/Constant ' num2str(i)],0,i*50);
        add_block('Simulink/Sinks/Out1',[TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/' v ' neutral']);
        fix_pos([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/<signal1>'],[TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/' v ' neutral'],0,i*50);
        line_name = add_line([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation')],['Constant ' num2str(i) '/1'],[v ' neutral/1'],'autorouting','on');
        set_param(line_name,'Name',['Constant ' num2str(i)]);
        set_param(Outline_name.Outport(i),'Name',v);
        
    end
    
    delete_line([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation')],'<Feature generation>/1','<signal1>/1');
    delete_block([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/<Feature generation>']);
    delete_block([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/<signal1>']);
    
% check the switch in the Preconditions level
% if no input signal into them, delete
SwitchName = find_system([TestdataBlock m1], 'SearchDepth',1,'BlockType','Outport');
for i = 1:length(SwitchName)
    OutputSigName = get_param(SwitchName{i},'Name');
    SwitchName2 = ['PrecAct ' OutputSigName];
    SwitchInputs = get_param([TestdataBlock m1 '/' SwitchName2],'Inputs');
    if str2num(SwitchInputs) == 2
       SwitchLine = get_param([TestdataBlock m1 '/' SwitchName2],'Linehandles');
       delete_line(SwitchLine.Outport);
       delete_line(SwitchLine.Inport(1));
       delete_block([TestdataBlock m1 '/' SwitchName2]);
       add_block('Simulink/Sources/Constant',[TestdataBlock m1 '/' OutputSigName ' random']);
       set_param([TestdataBlock m1 '/' OutputSigName ' random'], 'LinkStatus', 'none');
       set_param([TestdataBlock m1 '/' OutputSigName ' random'],'Value','0');
       fix_pos([TestdataBlock m1 '/' OutputSigName],[TestdataBlock m1 '/' OutputSigName ' random'],-200,-20);
       line_name = add_line([TestdataBlock m1],[OutputSigName ' random' '/1'],[OutputSigName '/1'],'autorouting','on');
       set_param(line_name, 'Name', OutputSigName);
    else
        Init_Ports = get_param([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation') '/' OutputSigName ' neutral'],'Port');
        line_name = add_line([TestdataBlock m1],[sprintf('Initialisation &\nStabilisation') '/' Init_Ports],[SwitchName2 '/' SwitchInputs],'autorouting','on');
        set_param(line_name,'Name',[OutputSigName ' neutral']);
        set_param([TestdataBlock m1 '/' SwitchName2],'Inputs',num2str(str2num(SwitchInputs)-1));
    end
end
%

% if there is just only one signal into 'Bus Creator 1'
% delete the redundant ports
inports = get_param([TestdataBlock m1 '/Bus Creator 1'],'Linehandles');
inports_l = length(inports.Inport);


for m = 1:inports_l
   if inports.Inport(m) == -1
       
       freeports = str2num(get_param([TestdataBlock m1 '/Bus Creator 1'],'Inputs'))-1;
       set_param([TestdataBlock m1 '/Bus Creator 1'],'Inputs',num2str(freeports));
       break;
   end
end

% if there is no signal out of the 'out bus'.delete 
OutbusLine = get_param([TestdataBlock m1 sprintf('/Out\nBus')],'Linehandles');
if OutbusLine.Outport == -1
    delete_line(Testdata_block,[sprintf('Out\nBus') '/1'],[m1 '/1']);
    delete_block([TestdataBlock m1 sprintf('/Out\nBus')]);
end
fix_pos([TestdataBlock m1 '/' OutputSigName],[TestdataBlock m1 sprintf('/Initialisation &\nStabilisation')],-180,200);
%fix_pos([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation')],[TestdataBlock m1 '/' sprintf('Sequencing of test data in time\ndue to Preconditions')],0,-100);

% refine the 'Sequencing of test data in time...' stateflow block
free_act = get_param([TestdataBlock m1 '/' sprintf('Sequencing of test data in time\ndue to Preconditions')], 'Linehandles');

    rt = sfroot;
    m = rt.find('-isa', 'Stateflow.State','Name','Precondition1');
    for i = 1:length(m)
        p = m(i).Path;
        p_name = get_param(p,'parent');
        if strcmp(p_name, [TestdataBlock m1]) == 1
            parent = m(i).Chart;
            son = m(i);
            break;
        end
    end
    
    if state_in_nr>1
        for i = 1:(state_in_nr-1)
            d1 = Stateflow.Data(parent);
            d1.Scope = 'Input';
            d1.Name=['Activate' num2str(i)];
            d1.Props.Type.Method = 'Inherited';
            add_line([TestdataBlock m1],['Bus Selector Seq' '/' num2str(i)],[sprintf('Sequencing of test data in time\ndue to Preconditions') '/' num2str(i)],'autorouting','on');
        end
        add_line([TestdataBlock m1],['Bus Selector Seq' '/' num2str(state_in_nr)],[sprintf('Sequencing of test data in time\ndue to Preconditions') '/' num2str(state_in_nr)],'autorouting','on');
    end
    start_state = parent.find('-isa', 'Stateflow.State','Name','Precondition1');
    stop_state = parent.find('-isa', 'Stateflow.State','Name','stop');
    tran1 = parent.find('-isa', 'Stateflow.Transition','Source',stop_state);
    tran2 = parent.find('-isa', 'Stateflow.Transition','Destination',start_state);
    tr = tran2(2);
    tran3 = parent.find('-isa', 'Stateflow.Transition','Destination',stop_state);
    
    s1 = start_state.find('-isa', 'Stateflow.State','Name','Init1');
    
    s3 = start_state.find('-isa', 'Stateflow.State','Name','Stabilise1');
    
    % calculate the time of Precondition Duration
    label = start_state.find('-isa', 'Stateflow.Transition','Source',s1);
    t1 = label.LabelString;
    t1_dot = findstr(t1, ',')-1; % e.g. 'after(100, tick)'
    t1_time = t1(7: t1_dot);
    label_2 = start_state.find('-isa', 'Stateflow.Transition','Destination',s3);
    t2 = label_2.LabelString;
    t2_dot = findstr(t2, ',')-1; % e.g. 'after(100, tick)'
    t2_time = t2(7: t2_dot);
    
        
    t3 = tran3.LabelString;
    t3_dot = findstr(t3, ',')-1; % e.g. 'after(100, tick)'
    t3_time = t3(7: t3_dot);
    % Test Case Duration = TCD
    TCD = p_nr * str2double(t3_time) + (str2double(t1_time)+str2double(t2_time))*p_nr;
    % variant duration VD_TIME
    VD_TIME = str2double(t3_time)+str2double(t1_time)+str2double(t2_time);
    
    s = tran3.Source;
    Position = son.Position;
    
    % add a transition state, since the condition time 'after' cannot be added in
    % the start state
     sA_4 = Stateflow.State(parent);
     sA_4.Name = 'wait';
     sA_4.LabelString = ['wait' sprintf('\n') 'entry: TDPre = ' num2str(p_nr+1) ';'];
     sA_4.Position = [200 170 100 40];
     
     tr.Destination = sA_4;
     tA4A1 = Stateflow.Transition(parent);
     if TCD_Previous==0
          tA4A1.LabelString = '';
     else
          tA4A1.LabelString = ['after(' num2str(TCD_Previous) ', tick)'];
     end
    
     tA4A1.Source = sA_4;
     tA4A1.Destination = start_state;
     tA4A1.SourceOClock = 3.;
     tA4A1.DestinationOClock = 9.;
    if p_nr==1
        s1.LabelString = ['Init' num2str(1) sprintf('\n') 'entry: TDPre = ' num2str(1) ';'];
        s3.LabelString = ['Stabilise' num2str(1) sprintf('\n') 'entry: TDPre = ' num2str(1) ';'];
    end
    if p_nr>1
%         s1.LabelString = ['Init' num2str(1) sprintf('\n') 'entry: TDPre = ' num2str(p_nr+1) ';'];
%         s3.LabelString = ['Stabilise' num2str(1) sprintf('\n') 'entry: TDPre = ' num2str(p_nr+1) ';'];
        s1.LabelString = ['Init' num2str(1) sprintf('\n') 'entry: TDPre = ' num2str(1) ';'];
        s3.LabelString = ['Stabilise' num2str(1) sprintf('\n') 'entry: TDPre = ' num2str(1) ';'];
        for i = 2:p_nr
            sA = Stateflow.State(parent);
            sA.Name = ['Precondition' num2str(i)];
            
            sA.Position = Position;
            sA.Position(2) = Position(2)+300;
            Position = sA.Position;
            % inside of sA
            sA_1 = Stateflow.State(sA);
            sA_1.Name = ['Init' num2str(i)];
            sA_1.LabelString = ['Init' num2str(i) sprintf('\n') 'entry: TDPre = ' num2str(i) ';'];
            Position_1 = sA_1.Position;
            sA_1.Position(4) = Position_1(4)-30;
            sA_1.Position(3) = Position_1(3)+40;
            
            sA_2 = Stateflow.State(sA);
            sA_2.Name = ['TDataPre' num2str(i)];
            sA_2.LabelString = ['TDataPre' num2str(i) sprintf('\n') 'entry: TDPre = ' num2str(i) ';'];
            Position1 = sA_1.Position;
            sA_2.Position = Position1;
            sA_2.Position(2) = Position1(2)+50;
            sA_3 = Stateflow.State(sA);
            sA_3.Name = ['Stabilise' num2str(i)];
            sA_3.LabelString = ['Stabilise' num2str(i) sprintf('\n') 'entry: TDPre = ' num2str(i) ';'];
            sA_3.Position = Position1;
            sA_3.Position(2) = Position1(2)+100;
            
            tA1A2 = Stateflow.Transition(sA);
            
            tA1A2.LabelString = ['after(' t1_time ', tick)'];
            tA1A2.Source = sA_1;
            tA1A2.Destination = sA_2;
            tA1A2.SourceOClock = 6.;
            tA1A2.DestinationOClock = 0.;
            
            tA2A3 = Stateflow.Transition(sA);
            
            tA2A3.LabelString = ['after(' t2_time ', tick)'];
            tA2A3.Source = sA_2;
            tA2A3.Destination = sA_3;
            tA2A3.SourceOClock = 6.;
            tA2A3.DestinationOClock = 0.;
            %
            tA0A1 = Stateflow.Transition(parent);
            tA0A1.LabelString = ['after(' t3_time ', tick)'];
            tA0A1.Source = s;
            tA0A1.Destination = sA_1;
            tA0A1.SourceOClock = 6.;
            tA0A1.DestinationOClock = 0.;
            
            s = sA_3;
            if i == p_nr && free_act.Inport == -1

                tranf = Stateflow.Transition(parent);
                tranf.LabelString = ['after(' t3_time ', tick)'];
                tranf.Source = sA_3;
                tranf.Destination = sA_4;
                tranf.SourceOClock = 9.;
                tranf.DestinationOClock = 9.;
            end
            if i == p_nr && free_act.Inport ~= -1

                tranf = Stateflow.Transition(parent);
                tranf.LabelString = ['after(' t3_time ', tick)'];
                tranf.Source = sA_3;
                tranf.Destination = stop_state;
                tranf.SourceOClock = 3.;
                tranf.DestinationOClock = 6.;
            end
        end
    end
    
     
    if free_act.Inport == -1
        
        tr.LabelString = '';
        tran1.LabelString = '';
        if p_nr > 1
            stop_state.delete;
            tran1.delete;
            tran3.delete;
        end
        
    else
        if p_nr > 1
            
            
            tran3.delete;
        end
    end
% clean the bus creator 2 free ports
% inports = get_param([TestdataBlock m1 '/Bus Creator 2'],'Linehandles');
% if inports.Inport(1) == -1
%    delete_line(inports.Outport);
%    delete_block([TestdataBlock m1 '/Bus Creator 2']);
% 
% end


%
vr_max = max(vr_max); 