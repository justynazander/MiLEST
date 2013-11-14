
function [] = TestdataGen() % SUTmodelName )

% Generate a new Test Data Achitecture related to the VFs
% the new Model name with surfix '_TC'  
%clear all; 
clear;
clc;
SOURCE = 'SpeedControlTest_vDemo';
SUTName = 'Speed control';

%% SUTName = 'PedalInterpretation';
load_system('Simulink'); % Load Simulink library (background)
load_system('MIL_Test');
load_system(SOURCE);
TARGET = [SOURCE '_TC'];
copyfile([SOURCE '.mdl'], [TARGET '.mdl'])
load_system(TARGET);
% building the generic test structure
add_block('MIL_Test/Test Data/Test Data Architecture/<Test data generator>', [TARGET '/TestData 1']);
set_param([TARGET '/TestData 1'], 'LinkStatus', 'none');
set_param([TARGET '/TestData 1'], 'BackgroundColor','cyan');
set_param([TARGET '/TestData 1'], 'Mask','Off');
block = [TARGET '/TestData 1'];
%-----caculate the number of the Signal in the test data---------------
%
% virture: consider the case: 'sig1' '' 'sig4' '' 'sig7' from the SUT 
% '' means a Bus exist between Source and SUT
% limit: consumption there is just one Bus between Source and SUT
InputName = get_param([TARGET '/' SUTName], 'InputSignalNames');
count = length(InputName);
SigNr = count;
for i = 1:count
   if isempty(InputName{i}) == 1
        
        src = get_param([TARGET '/' SUTName],'Linehandles');
        src1 = get_param(src.Inport(i),'SrcBlockHandle');
        name = get_param(src1, 'InputSignalNames');
        InputName{i} = name;
        SigNr = count + length(name)-1;
    end
end
%$$$$$$$
%
%==============================================================
ReqNr = length(find_system([TARGET '/Validation Functions'], 'regexp', 'on','LookUnderMasks','all','Name','Test Info'));
% SigNr = length(find_system([TARGET '/Validation Functions'], 'regexp', 'on','LookUnderMasks','all','Name','Test Info'));
Test_D_Gen_Sig(block,SigNr);
Test_D_Gen_Req(block,ReqNr);
add_block('Simulink/Sources/Constant', [block '/zero']);
set_param([block '/zero'],'Value','0');
%
%SwitchPortsNr = get_param([block '/<Requirement name>' '/switch <signal' num2str(1) '>'],'Inputs');
% replace_block(TARGET,'TestData','TestData 1');
%
%------reorgnization the lines between requirement name and switch
% generate bus creator to better layout
add_block('Simulink/Signal Routing/Bus Creator',[block '/Bus Creator 1']);
fix_pos([block sprintf('/Bus\nSelector')],[block '/Bus Creator 1'],0,100*length(ReqNr));
position = get_param([block '/Bus Creator 1'], 'Position');
position(2) = position(2)-length(ReqNr)*20;
set_param([block '/Bus Creator 1'], 'Position',position);
%==
fix_pos([block '/<Requirement name>'],[block '/zero'],100,-140);
fix_pos([block sprintf('/Test Ctrl\nInfluence')],[block sprintf('/Out\nBus')],-200,35);
SigAtTLines = get_param([block '/<Requirement name>'],'LineHandles');
      for j = 1 : SigNr
      delete_line(SigAtTLines.Outport(j));
      
      end
      fix_pos([block '/zero'],[block '/<Requirement name>'],-250,140);
for i = 2:ReqNr
      SigAtTLines = get_param([block '/<Requirement name>' num2str(i)],'LineHandles');
      for j = 1 : SigNr
      delete_line(SigAtTLines.Outport(j));
      end
      fix_pos([block '/zero'],[block '/<Requirement name>' num2str(i)],-250,140*i);
end
for k = 1:SigNr
      set_param([block '/switch <signal' num2str(k) '>'], 'Inputs', num2str(ReqNr+1));
      add_line(block,['zero/' num2str(1)],['switch <signal' num2str(k) '>/' num2str(2)],'autorouting','on');
end
for m = 1 : SigNr
      %add_line(block,['<Requirement name>/' num2str(m)],['switch <signal' num2str(m) '>/' num2str(3)],'autorouting','on');
      % for bus creator
      inports = get_param([block '/Bus Creator 1'],'Linehandles');
       inports_l = length(inports.Inport);
       %portNr = get_param(In{k},'Port');
       free_port = 0;
       for m1 = 1:inports_l
           if inports.Inport(m1) == -1
               free_port = 1;
               line_name = add_line(block,['<Requirement name>/' num2str(m)],['Bus Creator 1' '/' num2str(m1)],'autorouting','on');
               %set_param(line_name,'Name',v);
               break;
           end
       end
       if free_port == 0
           freeports = str2num(get_param([block '/Bus Creator 1'],'Inputs'))+1;
           set_param([block '/Bus Creator 1'],'Inputs',num2str(freeports));
           line_name = add_line(block,['<Requirement name>/' num2str(m)],['Bus Creator 1' '/' num2str(freeports)],'autorouting','on');
           %set_param(line_name,'Name',v);
       end
       %==
end
for i = 2:ReqNr
      for m = 1 : SigNr
      %add_line(block,['<Requirement name>' num2str(i) '/' num2str(m)],['switch <signal' num2str(m) '>/' num2str(i+2)],'autorouting','on');
       % for bus creator
      inports = get_param([block '/Bus Creator 1'],'Linehandles');
       inports_l = length(inports.Inport);
       %portNr = get_param(In{k},'Port');
       free_port = 0;
       for m1 = 1:inports_l
           if inports.Inport(m1) == -1
               free_port = 1;
               line_name = add_line(block,['<Requirement name>' num2str(i) '/' num2str(m)],['Bus Creator 1' '/' num2str(m1)],'autorouting','on');
               %set_param(line_name,'Name',v);
               break;
           end
       end
       if free_port == 0
           freeports = str2num(get_param([block '/Bus Creator 1'],'Inputs'))+1;
           set_param([block '/Bus Creator 1'],'Inputs',num2str(freeports));
           line_name = add_line(block,['<Requirement name>' num2str(i) '/' num2str(m)],['Bus Creator 1' '/' num2str(freeports)],'autorouting','on');
           %set_param(line_name,'Name',v);
       end
       %==
      end
end

%====
%$$$$$
%----- set the name of the Output signal and switch name in Testdata
%same virture and limit as --caculate the number of the Signal in the testdata
InputName = get_param([TARGET '/' SUTName], 'InputSignalNames');
k = 1;
for i = 1:length(InputName)
    
    if isempty(InputName{i}) == 0
        set_param([block '/<signal' num2str(k) '>'],'Name',InputName{i});
        set_param([block '/switch <signal' num2str(k) '>'],'Name',['PrecAct ' InputName{i}]);
        port_name_h = get_param(block,'Porthandles');
        set_param(port_name_h.Outport(k), 'Name',InputName{i}); % set the Outport name for the 'Testdata' block
        for l = 1:ReqNr % set the name of the Output signal and switch name in Testdata/Requirement
            if l==1
            set_param([block '/<Requirement name>/switch <signal' num2str(k) '>'],'Name',['PrecAct ' InputName{i}]);
            set_param([block '/<Requirement name>/<signal' num2str(k) '>'],'Name',InputName{i});
            
            else
            set_param([block '/<Requirement name>' num2str(l) '/switch <signal' num2str(k) '>'],'Name',['PrecAct ' InputName{i}]);
            set_param([block '/<Requirement name>' num2str(l) '/<signal' num2str(k) '>'],'Name',InputName{i});
            
            
            end
        end
        k=k+1;
    else
        
        src = get_param([TARGET '/' SUTName],'Linehandles');
        src1 = get_param(src.Inport(i),'SrcBlockHandle');
        name = get_param(src1, 'InputSignalNames');
        for j = 1:length(name) 
            set_param([block '/<signal' num2str(k) '>'],'Name',name{j});
            set_param([block '/switch <signal' num2str(k) '>'],'Name',['PrecAct ' name{j}]);
            for l = 1:ReqNr % set the name of the Output signal and switch name in Testdata/Requirement
                if l==1
                   set_param([block '/<Requirement name>/switch <signal' num2str(k) '>'],'Name',['PrecAct ' name{j}]);
                   set_param([block '/<Requirement name>/<signal' num2str(k) '>'],'Name',name{j});
                else
                   set_param([block '/<Requirement name>' num2str(l) '/switch <signal' num2str(k) '>'],'Name',['PrecAct ' name{j}]);
                   set_param([block '/<Requirement name>' num2str(l) '/<signal' num2str(k) '>'],'Name',name{j});
               end
            end
            k=k+1;
        end
    end
end


%$$$$$ set the name of the Output signal and switch name in Testdata
%
%==================================================================
% replace the TestData with TestData1
% virture: identify the signal automatically
position = get_param([TARGET '/TestData'],'Position');
set_param(block,'Position',position);
lines = get_param([TARGET '/TestData'],'Linehandles');
if length(lines.Outport)>0
    for i = 1:length(lines.Outport)
        srcT = get_param(lines.Outport(i),'DstBlockHandle');
        srcT_N = get_param(lines.Outport(i),'Name');
        srcP = get_param(lines.Outport(i),'DstPortHandle');
        srcT = get_param(srcT,'Name');
        srcP = get_param(srcP, 'PortNumber');
        Signr_1 = length(srcP);
        if Signr_1>1
          for j = 1:Signr_1
            delete_line(TARGET,['TestData/' num2str(i)],[srcT{j} '/' num2str(srcP{j})]);
            line_name = add_line(TARGET,['TestData 1/' num2str(i)],[srcT{j} '/' num2str(srcP{j})],'autorouting','on');
            set_param(line_name, 'Name', srcT_N);
          end
        else
            
            delete_line(TARGET,['TestData/' num2str(i)],[srcT '/' num2str(srcP)]);
            line_name = add_line(TARGET,['TestData 1/' num2str(i)],[srcT '/' num2str(srcP)],'autorouting','on');
            set_param(line_name, 'Name', srcT_N);
        end
    end
end
    
if length(lines.Inport)>0
    for i = 1:length(lines.Inport)
        if lines.Inport(i) ~= -1
          srcT = get_param(lines.Inport(i),'SrcBlockHandle');
          srcP = get_param(lines.Inport(i),'SrcPortHandle');
          srcT = get_param(srcT,'Name');
          srcP = get_param(srcP, 'PortNumber');
          delete_line(TARGET,[srcT '/' num2str(srcP)],['TestData/' num2str(i)]);
          add_line(TARGET,[srcT '/' num2str(srcP)],['TestData 1/' num2str(i)],'autorouting','on');
        end
    end
end
TestcontrolGen(TARGET)
delete_block([TARGET '/TestData']);

%$$$$
TestdataReqG([TARGET '/Validation Functions'],'Test Info',TARGET);
% generate bus selector for better layout
In = find_system(block, 'SearchDepth',1,'BlockType','Outport');% the name of Input Signal
for k = 1:length(In)
    v = get_param(In{k},'Name');
    add_block('Simulink/Signal Routing/Bus Selector',[block '/Bus Selector ' v]);
    fix_pos([block '/PrecAct ' v],[block '/Bus Selector ' v],-100,-50);
    position = get_param([block '/Bus Selector ' v], 'Position');
    position(2) = position(2)-length(ReqNr)*8;
    set_param([block '/Bus Selector ' v], 'Position',position);
    add_line(block,['Bus Creator 1' '/1'],['Bus Selector ' v '/1'],'autorouting','on');
    insignal = get_param([block '/Bus Selector ' v], 'Inputsignals');
    outsignal = [];
    for i = 1:length(insignal)
        q = findstr(insignal{i}, v);
        if isempty(q) == 0
            outsignal = [outsignal ',' insignal{i}];
        end
    end
    outsignal = outsignal(2:end);
    set_param([block '/Bus Selector ' v], 'Outputsignals', outsignal);
    ph = get_param([block '/Bus Selector ' v],'Porthandles');
    
    for i = 1:length(ph.Outport)
        freeports = str2num(get_param([block '/PrecAct ' v],'Inputs'));
        %set_param([block '/PrecAct ' v],'Inputs',num2str(freeports));
        add_line(block,['Bus Selector ' v '/' num2str(i)],['PrecAct ' v '/' num2str(2+i)],'autorouting','on');
        
    end
end
out = get_param([block sprintf('/Out\nBus')], 'Linehandles');
if out.Outport(1) == -1
    disp('No Out Bus Signal');
else
    p = get_param(out.Outport,'DstBlockHandle');
    for i = 1:length(p)
        delete_line(block,[sprintf('Out\nBus') '/' num2str(1)],[get_param(p(i), 'Name') '/' num2str(1)]);
        add_line(block,[sprintf('Out\nBus') '/' num2str(1)],[get_param(p(i), 'Name') '/' num2str(1)],'autorouting','on');
    end
end
% get the value for state flow
after = find_system([TARGET '/Validation Functions'],'SearchDepth',2,'regexp', 'on','LookUnderMasks','all','Name','after');
after_nr = length(after);
for i = 1:after_nr
    after_name = get_param(after{i},'name');
    after_name_t = after_name(1:5);
    if strcmp(after_name_t,'after') == 1
        t = after_name((length('after (')+1):(length('after (')+1));
        pa = get_param(after{i},'Parent');
        pa_t = [strrep(pa,'Validation Functions','TestData 1') sprintf('/Sequencing of test data in time\ndue to Preconditions')];
    end
end
%==========get the value for state flow
save_system;
disp(sprintf('Test Structure "%s" for "%s" built.', TARGET, SOURCE));


