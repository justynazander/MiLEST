
function TransformationStep4() % SUTmodelName )

%TRANSFORMATIONSTEP2 Summary of this function goes here
%   Detailed explanation goes here
%clear all; 
clear;
clc;
SUTmodelName = 'Softstarter';
SOURCE = SUTmodelName;
load_system('Simulink'); % Load Simulink library (background)
load_system('MIL_Test');
load_system(SOURCE);
SUTblockName = 'Softstarter';
%SUTblockName = get_param(find_system(SUTmodelName, 'BlockType', 'SubSystem'), 'Name'); 
%SUTblockName = SUTblockName{1};
TARGET = [SOURCE '_TC'];
%new_system(TARGET);
copyfile([SOURCE '.mdl'], [TARGET '.mdl'])
load_system(TARGET);
%-------------------------------------
% clear TARGET to start transformation
% should be in the preTransformation phase
terminators = find_system(SOURCE,  'SearchDepth', 1, 'regexp', 'on', 'BlockType', 'Terminator', 'Name', 'Terminator_');
grounds = find_system(SOURCE,  'SearchDepth', 1, 'regexp', 'on', 'BlockType', 'Ground', 'Name', 'Ground_');
lenTer = length(terminators);
lenGr = length(grounds);
termLines = get_param([TARGET '/' SUTblockName],'LineHandles');
for i = 1:lenTer
    delete_block([TARGET '/Terminator_' num2str(i)])
    delete_line(termLines.Outport(i));
end
for i = 1:lenGr
    delete_block([TARGET '/Ground_' num2str(i)])
    delete_line(termLines.Inport(i));
end

%-------------------------------------
% building the generic test structure

add_block('MIL_Test/Validation Function/Test Evaluation Architecture/<system name>', [TARGET '/<Test oracle>']);
add_block('Simulink/Sinks/Display',[TARGET '/OverallVerdict']);
%add_block('Simulink/Sinks/To Workspace',[TARGET '/OverallVerdictVar']);
%set_param([TARGET '/OverallVerdictVar'], 'VariableName', 'OverallVerdict');
set_param([TARGET '/<Test oracle>'], 'LinkStatus', 'none')        
set_param([TARGET '/OverallVerdict'], 'Position',[1135 533 1215 557]);
%set_param([TARGET '/OverallVerdictVar'], 'Position',[1140 387 1215 413]);
set_param([TARGET '/<Test oracle>'], 'Position',[910 509 1040 556]);
%add_line(TARGET,['<Test oracle>/2'],['OverallVerdictVar/1'],'autorou
%ting','on');
add_block('Simulink/Commonly Used Blocks/Bus Selector', [TARGET '/BSOV']);
set_param([TARGET '/BSOV'], 'Position',[1075 516 1080 554]);
set_param([TARGET '/BSOV'], 'OutputSignals', 'OverallVerdict')
add_line(TARGET,['<Test oracle>/1'],['BSOV/1'],'autorouting','on');
add_line(TARGET,['BSOV/1'],['OverallVerdict/1'],'autorouting','on');


add_block('Simulink/Commonly Used Blocks/Bus Creator', [TARGET '/BCOut']);
add_block('Simulink/Commonly Used Blocks/Bus Creator', [TARGET '/BCIn']);
add_block('Simulink/Commonly Used Blocks/Bus Creator', [TARGET '/BCInOut']);
set_param([TARGET '/BCOut'], 'Position',[800 441 805 534]);
set_param([TARGET '/BCIn'], 'Position',[800 541 805 619]);
set_param([TARGET '/BCInOut'], 'Position',[870 444 875 626]);


add_block('MIL_Test/Test Data/Test Data Architecture/<Test data generator>',[TARGET '/<Test data generator>']);
set_param([TARGET '/<Test data generator>'], 'Position',[120 520 270 610]);
%set_param([TARGET '/Test Stimuli'], 'Ports', [0 lenGr 0 0 0 0 0 0] -f);
%add_block([TARGET '/<Test data generator>/<signal1>'],[TARGET '/<Test data generator>/<signal2>']);
%fix_pos(['MIL_Test/Test Data/Test Data Architecture/<Test data generator>'],[TARGET '/<Test data generator>/<signal2>'],0,150);


add_line(TARGET,['BCOut/1'],['BCInOut/1'],'autorouting','on');
add_line(TARGET,['BCOut/1'],['<Test data generator>/2'],'autorouting','on');
add_line(TARGET,['BCIn/1'],['BCInOut/2'],'autorouting','on');
add_line(TARGET,['BCInOut/1'],['<Test oracle>/1'],'autorouting','on');
% set number of inputs to the bus
SUT_signal = get_param([TARGET '/' SUTblockName], 'Linehandles');
SUT_outsignal_nr = length(SUT_signal.Outport);
set_param([TARGET '/BCOut'], 'Inputs', num2str(SUT_outsignal_nr));
%set_param([TARGET '/BCIn'], 'Inputs', num2str(lenGr)); % todo - dep. on the buses inside the sut
for i = 1:SUT_outsignal_nr
add_line(TARGET,[SUTblockName '/' num2str(i)],['BCOut/' num2str(i)],'autorouting','on');
end

SUT_insignal_nr = length(SUT_signal.Inport);
set_param([TARGET '/BCIn'], 'Inputs', num2str(SUT_insignal_nr));


% analysis of Signals coming into the SUT
%add_block('Simulink/Commonly Used Blocks/Bus Creator', [TARGET '/BCInSUT']);
%set_param([TARGET '/BCInSUT'], 'Position',[445 371 450 444]);

% add_line(TARGET,['Test Stimuli/1'],['BCInSUT/1'],'autorouting','on');
% add_line(TARGET,['BCInSUT/1'],[SUTblockName '/1'],'autorouting','on');
BusSelInSUT = find_system([SUTmodelName '/' SUTblockName], 'BlockType', 'BusSelector');
DemInSUT =find_system([SUTmodelName '/' SUTblockName], 'BlockType', 'Demux');

% todo - busselctors 
% if BusSelInSUT ~= 0 | DemInSUT ~= 0
%     disp('aha')
% end 

%addterms(TARGET);

%==========================================================================
%==========================================================================
load_system([TARGET '/<Test data generator>']);
% this is very important to disable the link of subsystem, or u will not have the right to change subsystem
% in this situation
set_param([TARGET '/<Test data generator>'],'LinkStatus', 'none');
In_SUT = find_system([TARGET '/' SUTblockName], 'SearchDepth', 1, 'BlockType', 'Inport');
n = length(In_SUT);
Test_D_Gen_S([TARGET '/<Test data generator>'],n);
set_param([TARGET '/<Test data generator>'],'MaskValues', {'1',num2str(n)});
delete(SUT_signal.Inport);
for i = 1:SUT_insignal_nr
    
    add_line(TARGET,['<Test data generator>/' num2str(i)],['BCIn/' num2str(i)],'autorouting','on');
    add_line(TARGET,['<Test data generator>/' num2str(i)],[SUTblockName '/' num2str(i)],'autorouting','on');
end

set_param([TARGET '/<Test data generator>'],'Name', 'TestData');
set_param([TARGET '/<Test oracle>'],'Name', 'Validation Functions');
%==========================================================================
save_system;
disp(sprintf('Test Structure "%s" for "%s" built.', TARGET, SOURCE));


