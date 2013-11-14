function [] = GenVarSequence_1 (path, ReqNr)
% Sync. the partitioned variants using stateflow
% for each set of generated variants a control part should be added 
%
% design outside connection

add_block('Simulink/Ports & Subsystems/Subsystem',[path sprintf('/TestDataVariants Sequence')]); 
iTestC = [path sprintf('/TestDataVariants Sequence')];
set_param(iTestC, 'LinkStatus', 'none');
fix_pos([path '/switch'], iTestC, -70, 70);

add_block('Simulink/Signal Routing/From',[path sprintf('/TestDataVariants Sequence') '/From']);
set_param([path sprintf('/TestDataVariants Sequence') '/From'], 'LinkStatus', 'none');
fix_pos([path sprintf('/TestDataVariants Sequence') '/In1'], [path sprintf('/TestDataVariants Sequence') '/From'], 0, 0);
in1_l = get_param([path sprintf('/TestDataVariants Sequence') '/In1'],'Linehandles');
delete_line(in1_l.Outport);
delete_block([path sprintf('/TestDataVariants Sequence') '/In1']);
add_block('Simulink/Sources/Constant',[path sprintf('/TestDataVariants Sequence') '/Constant']);
set_param([path sprintf('/TestDataVariants Sequence') '/Constant'], 'LinkStatus', 'none');
set_param([path sprintf('/TestDataVariants Sequence') '/Constant'], 'Value', num2str(ReqNr));
fix_pos([path sprintf('/TestDataVariants Sequence') '/From'],[path sprintf('/TestDataVariants Sequence') '/Constant'], 0, 70);
add_block(['Simulink/Logic and Bit Operations/' sprintf('Relational\nOperator')],[path sprintf('/TestDataVariants Sequence/Relational\nOperator')]);
set_param([path sprintf('/TestDataVariants Sequence/Relational\nOperator')], 'LinkStatus', 'none');
fix_pos([path sprintf('/TestDataVariants Sequence') '/From'],[path sprintf('/TestDataVariants Sequence/Relational\nOperator')], 100, 30);
add_line([path sprintf('/TestDataVariants Sequence')],['From' '/' num2str(1)],[sprintf('Relational\nOperator/') num2str(1)],'autorouting','on');
add_line([path sprintf('/TestDataVariants Sequence')],['Constant' '/' num2str(1)],[sprintf('Relational\nOperator/') num2str(2)],'autorouting','on');
add_block('Simulink/Signal Routing/Switch',[path sprintf('/TestDataVariants Sequence') '/Switch']);
set_param([path sprintf('/TestDataVariants Sequence') '/Switch'],'Criteria','u2 ~= 0');
set_param([path sprintf('/TestDataVariants Sequence') '/Switch'], 'LinkStatus', 'none');
fix_pos([path sprintf('/TestDataVariants Sequence/Relational\nOperator')],[path sprintf('/TestDataVariants Sequence') '/Switch'], 90, 0);
add_line([path sprintf('/TestDataVariants Sequence')],['Constant' '/' num2str(1)],['Switch/' num2str(3)],'autorouting','on');
add_line([path sprintf('/TestDataVariants Sequence')],['From' '/' num2str(1)],['Switch/' num2str(1)],'autorouting','on');
add_line([path sprintf('/TestDataVariants Sequence')],[sprintf('Relational\nOperator/') num2str(1)],['Switch/' num2str(2)],'autorouting','on');
add_line([path sprintf('/TestDataVariants Sequence')],['Switch/' num2str(1)],['Out1/' num2str(1)], 'autorouting','on');
add_line(path,[sprintf('TestDataVariants Sequence') '/' num2str(1)],['switch/' num2str(1)],'autorouting','on');


