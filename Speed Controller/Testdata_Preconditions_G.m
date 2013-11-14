function [] = Testdata_Preconditions_G(sys,m1,tar)

% Preconditions layer transform

TestdataBlock = [tar '/TestData 1/'];
Testdata_block = [tar '/TestData 1'];
%VFsBlock = 'LCTC_vTD8_Transformation4_TC/Validation Functions/';
VFsBlock = [tar '/Validation Functions/'];
Precon = find_system([sys '/' m1], 'SearchDepth',2,'regexp', 'on','LookUnderMasks','all','Name','Activate');

 % the number of the preconditions in this requirement one 'in' one 'out'
% generate the bus creator and bus seletor for better layout
add_block('Simulink/Signal Routing/Bus Creator',[TestdataBlock m1 '/Bus Creator 1']);
fix_pos([TestdataBlock m1 '/<Preconditions name>'],[TestdataBlock m1 '/Bus Creator 1'],20,100*length(Precon));
fix_pos([TestdataBlock m1 '/<Preconditions name>'], [TestdataBlock m1 sprintf('/Sequencing of test data in time\ndue to Preconditions')],125,-100);
position = get_param([TestdataBlock m1 '/Bus Creator 1'], 'Position');
position(2) = position(2)-length(Precon)*20;
set_param([TestdataBlock m1 '/Bus Creator 1'], 'Position',position);

%===
for j = 1:length(Precon)
    Act = Precon{j};
    ActOut = get_param(Act, 'Blocktype');
    if strcmp(ActOut, 'Outport') == 1
        R_Act = length(Act)-length('/Activate');
        F_Act = length([sys '/' m1 '/'])+1;
        ActName = Act(F_Act:R_Act); % Preconditions Name
        add_block('MIL_Test/Test Data/Test Data Architecture/<Test data generator>/<Requirement name>/<Preconditions name>',[TestdataBlock m1 '/' ActName]);
        set_param([TestdataBlock m1 '/' ActName], 'LinkStatus', 'none');
        TestdataFeature_G([VFsBlock m1 '/' ActName],[TestdataBlock m1 '/' ActName],tar);
        fix_pos([TestdataBlock m1 '/<Preconditions name>'],[TestdataBlock m1 '/' ActName],-150,j*120+50);
        In = find_system([TestdataBlock m1 '/' ActName], 'SearchDepth',1,'BlockType','Outport');% the name of Input Signal
        for k = 1:length(In)
               v = get_param(In{k},'Name');
               %In{k} = v;
            
            if strcmp(v,'Activate') == 1
                line_name = add_line([TestdataBlock m1],[ActName '/1'],sprintf('Sequencing of test data in time\ndue to Preconditions/1'),'autorouting','on');
                set_param(line_name,'Name',v);
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
       add_block('MIL_Test/Test Data/Feature generation/Generate constant',[TestdataBlock m1 '/' OutputSigName ' random']);
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

% if there is no signal out of the 'out bus'.delete 
OutbusLine = get_param([TestdataBlock m1 sprintf('/Out\nBus')],'Linehandles');
if OutbusLine.Outport == -1
    delete_line(Testdata_block,[sprintf('Out\nBus') '/1'],[m1 '/1']);
    delete_block([TestdataBlock m1 sprintf('/Out\nBus')]);
end
fix_pos([TestdataBlock m1 '/' OutputSigName],[TestdataBlock m1 sprintf('/Initialisation &\nStabilisation')],-180,200);
%fix_pos([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation')],[TestdataBlock m1 '/' sprintf('Sequencing of test data in time\ndue to Preconditions')],0,-100);
