function add_SR(model)

% adding signal range and partition point in the model for the input
% signals
TARGET = model;
load_system('Simulink'); % Load Simulink library (background)
load_system('MIL_Test');
load_system('LCTC_vTD8_Test_TC0_ref6_2007a');
load_system(TARGET);
TestDataBlock = find_system(TARGET,  'SearchDepth', 1, 'regexp', 'on', 'Name', 'TestData');
TestDataBlock_l = get_param(char(TestDataBlock),'Linehandles');
TestDataBlock_NAME= get_param(char(TestDataBlock),'Name');
for i = 1:length(TestDataBlock_l.Outport)
    sr = add_block('MIL_Test/Test Quality/Signal Range',[TARGET '/Signal Range ' num2str(i)]);
    %par = add_block('LCTC_vTD8_Test_TC0_ref6_2007a/Signal Range 1',[TARGET '/Partition Point ' num2str(i)]);
    fix_pos(char(TestDataBlock),[TARGET '/Signal Range ' num2str(i)],180,35*i-455);
    %fix_pos([TARGET '/Signal Range ' num2str(i)],[TARGET '/Partition Point ' num2str(i)],70,-30);
    dst = get_param(TestDataBlock_l.Outport(i),'DstBlockHandle');
   
    inputName = get_param(TestDataBlock_l.Outport(i),'Name');
    delete_line(TestDataBlock_l.Outport(i));
    l = add_line(TARGET,[TestDataBlock_NAME '/' num2str(i)],['Signal Range ' num2str(i) '/' num2str(1)],'autorouting','on');
    set_param(l,'Name',inputName);
    %add_line(TARGET,['Signal Range ' num2str(i) '/' num2str(1)],['Partition Point ' num2str(i) '/1'],'autorouting','on');
    for j=1:length(dst)
        dst_n = get_param(dst(j),'Name');
        l = add_line(TARGET,['Signal Range ' num2str(i) '/' num2str(1)],[dst_n '/' num2str(i)],'autorouting','on');
        set_param(l,'Name',inputName);
    end
end
save_system;