function [] = TestdataFeature_G(VFsName,TestDataName,tar)

% To design the Testdata Feature layer
load_system('Simulink'); % Load Simulink library (background)
load_system('MIL_Test');
set_param(TestDataName,'LinkStatus', 'none');

Model_name = get_param(VFsName,'Parent');
po = findstr(Model_name, '/')-1;
Model_name = Model_name(1:po);
% delete some lines and blocks to prepare 
delete_line(TestDataName,['Out Bus/' num2str(1)],['<Check>/' num2str(1)]);
delete_line(TestDataName,['<Check>/' num2str(1)],['Activate/' num2str(1)]);
delete_line(TestDataName,['Feature generation/' num2str(1)],['<signal1>/' num2str(1)]);
delete_block([TestDataName '/<Check>']);
delete_block([TestDataName '/Feature generation']);
delete_block([TestDataName '/<signal1>']);
%-----get Input Signal names
%SUTmodelName = 'LCTC_vTD8_Transformation4';
%SOURCE = SUTmodelName;
TARGET = tar;
In = find_system([TARGET '/TestData 1'], 'SearchDepth',1,'BlockType','Outport');% the name of Input Signal
for i= 1:length(In)
    v = In{i};
    v = v((length([TARGET '/TestData 1'])+2):length(v));
    In{i} = v;
end

isOut = 0; % to judge if there is Output Signal in the Bus Selector

%----2222Bus Seletor-----------
Bus = find_system(VFsName, 'SearchDepth',1,'regexp', 'on','Name',sprintf('Bus\nSelector'));
BP = length(find_system(VFsName, 'SearchDepth',1,'regexp', 'on','Name','Bound Precond'));

if length(Bus) > 0
OutSigName = get_param([VFsName '/' sprintf('Bus\nSelector')], 'OutputSignals'); % the  Outputsignals in the BUS e.g. Outputs.v_gh
OutSigName_N = get_param([VFsName '/' sprintf('Bus\nSelector')], 'OutputSignalNames'); % the name of Outputsignals e.g. <v_gh>
h = findstr(OutSigName,',');
Bus_Sel_Sig = '';
Bus_Sel_SigN = {};
if strcmp(OutSigName(1:1),'O') == 1 % judge the first signal is Output
        l1=length('Outputs.')+1;
        l2=length(OutSigName);
        %l11=length('Outputs.signal1.')+1;
        Bus_Sel_Sig = strcat(Bus_Sel_Sig,',',OutSigName(l1:l2));
        Bus_Sel_SigN1 = OutSigName_N{1};
        Bus_Sel_SigN1 = Bus_Sel_SigN1(2:(length(Bus_Sel_SigN1)-1));
        Bus_Sel_SigN = {Bus_Sel_SigN Bus_Sel_SigN1};
end
if isempty(h) == 0 % more than one Signal 
    for k=1:length(h)
        l3 = h(k)+1;
        if strcmp(OutSigName(l3:l3),'O') == 1 % 'O' judges 'outputs.'
            if k == length(h) %the last outputs signal
                l1 = h(k)+length('Outputs.')+1;
                l2 = length(OutSigName);
                
                %l11 = h(k)+length('Outputs.signal1.')+1;
                
                Bus_Sel_Sig = strcat(Bus_Sel_Sig,',',OutSigName(l1:l2));
                Bus_Sel_SigN1 = OutSigName_N{k+1};
                Bus_Sel_SigN1 = Bus_Sel_SigN1(2:(length(Bus_Sel_SigN1)-1));
                Bus_Sel_SigN = {Bus_Sel_SigN Bus_Sel_SigN1};
            else
                l1 = h(k)+length('Outputs.')+1;
                l2 = h(k+1)-1;
                %l11 = h(k)+length('Outputs.signal1.')+1;
                Bus_Sel_Sig = strcat(Bus_Sel_Sig,',',OutSigName(l1:l2));
                Bus_Sel_SigN1 = OutSigName_N{k+1};
                Bus_Sel_SigN1 = Bus_Sel_SigN1(2:(length(Bus_Sel_SigN1)-1));
                Bus_Sel_SigN = {Bus_Sel_SigN Bus_Sel_SigN1};
            end
        end
        
    end
end

Bus_Sel_Sig_Nr = length(findstr(Bus_Sel_Sig,','));
BSS = Bus_Sel_Sig(2:length(Bus_Sel_Sig));
if Bus_Sel_Sig_Nr > 0
    isOut = 1; % Flag for the Bus Selector
    add_block('Simulink/Signal Routing/Bus Selector',[TestDataName '/Bus Selector']);
    set_param([TestDataName '/Bus Selector'],'OutputSignals',BSS);
    fix_pos([TestDataName '/Out Bus'],[TestDataName '/Bus Selector'],120,-10);
    add_line(TestDataName,['Out Bus/' num2str(1)],['Bus Selector/' num2str(1)],'autorouting','on');
    for k = 1 : Bus_Sel_Sig_Nr
    add_block('Simulink/Discrete/Memory',[TestDataName '/Memory ' Bus_Sel_SigN{k+1}]);
    fix_pos([TestDataName '/Bus Selector'],[TestDataName '/Memory ' Bus_Sel_SigN{k+1}],k*120,k*80);
    add_line(TestDataName,['Bus Selector/' num2str(k)],['Memory ' Bus_Sel_SigN{k+1} '/' num2str(1)],'autorouting','on');
    end
end
  
end

%$$$$$$$---Bus Seletor-----------
%22222222

%
%----Bound Precond---------
% Shut off the link status of all subsystem to find the 'Activate' etc.
% later

sub = find_system(VFsName,'SearchDepth',1, 'regexp', 'on','LookUnderMasks','all','Blocktype','SubSystem');
for i = 1:length(sub)
    set_param(sub{i}, 'LinkStatus', 'none');
    is_act = find_system(sub{i},'SearchDepth',1, 'regexp', 'on','LookUnderMasks','all','Name','Activate');
    is_act_l = length(is_act);
    is_ref = find_system(sub{i},'SearchDepth',1, 'regexp', 'on','LookUnderMasks','all','Name','Reference');
    is_ref_l = length(is_ref);
    is_sig = find_system(sub{i},'SearchDepth',1, 'regexp', 'on','LookUnderMasks','all','Name','Signal');
    is_sig_l = length(is_sig);
    if is_ref_l == 1 && is_sig_l == 1 % detect the Rel
     %if is_act_l == 1 && is_ref_l == 1 && is_sig_l == 1 % detect the Rel   
        v = get_param(sub{i}, 'MaskValues');
        g = get_param(sub{i}, 'Linehandles');
        Input1_block = get_param(g.Inport(1), 'SrcBlockHandle');
        Input1_block_name = get_param(Input1_block, 'name');
        if strcmp(Input1_block_name,sprintf('Bus\nSelector')) == 0 %between the bus selector and the block exists another blocks
            feature = get_param(Input1_block, 'Blocktype');
           
            is_constant = find_system(Input1_block,'SearchDepth',1,'LookUnderMasks','all','Name','Constant');
            is_signal = find_system(Input1_block,'SearchDepth',1,'LookUnderMasks','all','Name','Signal');
            is_increase = find_system(Input1_block,'SearchDepth',1,'LookUnderMasks','all','Name','Increase');
            is_decrease = find_system(Input1_block,'SearchDepth',1,'LookUnderMasks','all','Name','Decrease');
            is_step = find_system(Input1_block,'SearchDepth',1,'LookUnderMasks','all','Name','Step');
            is_Complete_step = find_system(Input1_block,'SearchDepth',1,'LookUnderMasks','all','Name','Complete step');
            is_Step_response = find_system(Input1_block,'SearchDepth',1,'LookUnderMasks','all','Name','Step response');
            if strcmp(feature, 'MATLABFcn') == 1
                name = get_param(Input1_block, 'Name');
                add_block('Simulink/User-Defined Functions/MATLAB Fcn',[TestDataName '/' name]);
                val = get_param(Input1_block, 'MATLABFcn');
                val1 = findstr(val, 'get_param');
                %
                g1 = get_param(sub{i}, 'Linehandles');
                InputName2 = get_param(g1.Inport(2), 'SrcBlockHandle');
                val_12 = get_param(InputName2, 'Value');
                %
                if isempty(val1) == 0
                    
                    val0 = val1 + length('get_param')+1;
                    val2 = findstr(val, ')') - 1;
                    val2 = val2(1);
                    path1 = val(val0:val2);
                    pos1 = findstr(path1,'/');
                    path2 = path1(pos1:end);
                    path = [sprintf('\''get_blockPath()')];
                    %path = [sprintf('\''get_blockPath()') path2];
                    Para = ['set_param(' 'get_blockPath()' ',' sprintf('\''') 'quat_par' sprintf('\''') ',' sprintf('\''') val_12 sprintf('\''') ')'];
                    set_param([TestDataName '/' name], 'MATLABFcn', Para);
                    % e.g. set_param('Quat_test_jza2_TC/SUT/Test_quaternion', 'quat_par', '[0,0,0,0]')
                end
            end
            if length(is_step) == 1 && length(is_Complete_step) ==1 && length(is_Step_response) == 0
                f = get_param(Input1_block, 'Linehandles');
                InputName = get_param(f.Inport, 'Name');
                InputName = InputName(2:(length(InputName)-1));
                add_block('MIL_Test/Test Data/Feature generation/Generate constant',[TestDataName '/Constant' num2str(i)],'Position',[435 i*50+100 470 i*50+135]);
                set_param([TestDataName '/Constant' num2str(i)], 'LinkStatus', 'none');
                add_block('Simulink/Sinks/Out1',[TestDataName '/' InputName]);
                fix_pos([TestDataName '/Constant' num2str(i)],[TestDataName '/' InputName],120,0);
                add_line(TestDataName,['Constant' num2str(i) '/' num2str(1)],[InputName '/' num2str(1)],'autorouting','on');
                % set Value for the constant
                dstBlockhandl = get_param(f.Outport, 'DstBlockHandle');
                dstBlock = get_param(dstBlockhandl, 'Linehandles');
                const = get_param(dstBlock.Inport(2), 'SrcBlockHandle');
                constVal = get_param(const, 'Value');
                set_param([TestDataName '/Constant' num2str(i)], 'Value', constVal);
            end
            % detect complete step
            if length(is_step) == 1 && length(is_Complete_step) ==1 && length(is_Step_response) == 1
                
                f = get_param(Input1_block, 'Linehandles');
                InputName = get_param(f.Inport(1), 'Name');
                InputName = InputName(2:(length(InputName)-1));
                add_block(['MIL_Test/Test Data/Feature generation/' 'Generate complete step'],[TestDataName '/Generate complete step ' num2str(i)],'Position',[335 i*50+200 370 i*50+235]);
                set_param([TestDataName '/Generate complete step ' num2str(i)], 'LinkStatus', 'none');
                add_block('Simulink/Sinks/Out1',[TestDataName '/' InputName]);
                fix_pos([TestDataName '/Out Bus'],[TestDataName '/Generate complete step ' num2str(i)],120*i,-100*i);

                %add_line(TestDataName,['Out Bus' '/' num2str(1)],['Generate complete step ' num2str(i) '/' num2str(1)],'autorouting','on');
                % connect the Memory block with the Complete step detection, match the
                % Outsignal

                add_line(TestDataName,['Out Bus' '/' num2str(1)],['Generate complete step ' num2str(i) '/' num2str(1)],'autorouting','on');
                fix_pos([TestDataName '/Generate complete step ' num2str(i)],[TestDataName '/' InputName],130,-25);
                add_line(TestDataName,['Generate complete step ' num2str(i) '/' num2str(1)],[InputName '/' num2str(1)],'autorouting','on');
            end
            if length(is_constant) == 1 && length(is_signal) ==1 % Detect Constant
                
                f = get_param(Input1_block, 'Linehandles');
                InputName = get_param(f.Inport, 'Name');
                InputName = InputName(2:(length(InputName)-1));
                add_block('MIL_Test/Test Data/Feature generation/Generate constant',[TestDataName '/Constant' num2str(i)],'Position',[435 i*50+100 470 i*50+135]);
                set_param([TestDataName '/Constant' num2str(i)], 'LinkStatus', 'none');
                add_block('Simulink/Sinks/Out1',[TestDataName '/' InputName]);
                fix_pos([TestDataName '/Constant' num2str(i)],[TestDataName '/' InputName],120,0);
                add_line(TestDataName,['Constant' num2str(i) '/' num2str(1)],[InputName '/' num2str(1)],'autorouting','on');
                % set Value for the constant
                dstBlockhandl = get_param(f.Outport, 'DstBlockHandle');
                dstBlock = get_param(dstBlockhandl, 'Linehandles');
                const = get_param(dstBlock.Inport(2), 'SrcBlockHandle');
                constVal = get_param(const, 'Value');
                ODT = get_param(const, 'OutDataTypeMode'); % set the same outdatatypemode as the source
                set_param([TestDataName '/Constant' num2str(i)], 'Value', constVal);
                set_param([TestDataName '/Constant' num2str(i)], 'OutDataTypeMode', ODT);
            end
            if length(is_increase) ==1 && length(is_signal) ==1 % Detect Increase
                f = get_param(Input1_block, 'Linehandles');
                InputName = get_param(f.Inport, 'Name');
                InputName = InputName(2:(length(InputName)-1));
                add_block(['MIL_Test/Test Data/Feature generation/' sprintf('Generate \nlimited increase')],[TestDataName '/Limited Ramp ' num2str(i)],'Position',[435 i*50+50 470 i*50+85]);
                set_param([TestDataName '/Limited Ramp ' num2str(i)], 'LinkStatus', 'none');
                add_block('Simulink/Sinks/Out1',[TestDataName '/' InputName]);
                fix_pos([TestDataName '/Limited Ramp ' num2str(i)],[TestDataName '/' InputName],120,0);
                add_line(TestDataName,['Limited Ramp ' num2str(i) '/' num2str(1)],[InputName '/' num2str(1)],'autorouting','on');
                % set Value for the limited Ramp
                dstBlockhandl = get_param(f.Outport, 'DstBlockHandle');
                dstBlock = get_param(dstBlockhandl, 'Linehandles');
                const = get_param(dstBlock.Inport(2), 'SrcBlockHandle');
                constVal = get_param(const, 'Value');
                set_param([TestDataName '/Limited Ramp ' num2str(i)], 'XF', constVal);
            end
            if length(is_decrease) ==1 && length(is_signal) ==1 % Detect decrease  
                f = get_param(Input1_block, 'Linehandles');
                InputName = get_param(f.Inport, 'Name');
                InputName = InputName(2:(length(InputName)-1));
                add_block(['MIL_Test/Test Data/Feature generation/' sprintf('Generate \nlimited decrease')],[TestDataName '/Limited Ramp Down ' num2str(i)],'Position',[335 i*50+200 370 i*50+235]);
                set_param([TestDataName '/Limited Ramp Down ' num2str(i)], 'LinkStatus', 'none');
                add_block('Simulink/Sinks/Out1',[TestDataName '/' InputName]);
                fix_pos([TestDataName '/Limited Ramp Down ' num2str(i)],[TestDataName '/' InputName],120,0);
                add_line(TestDataName,['Limited Ramp Down ' num2str(i) '/' num2str(1)],[InputName '/' num2str(1)],'autorouting','on');
                % set Value for the limited Ramp
                dstBlockhandl = get_param(f.Outport, 'DstBlockHandle');
                dstBlock = get_param(dstBlockhandl, 'Linehandles');
                const = get_param(dstBlock.Inport(2), 'SrcBlockHandle');
                constVal = get_param(const, 'Value');
                set_param([TestDataName '/Limited Ramp Down ' num2str(i)], 'XF', constVal);
            end
        else % between the bus selector and Rel no block exists
            InputName = get_param(g.Inport, 'Name');
            InputName1 = InputName{1};
            InputName1 = InputName1(2:(length(InputName1)-1));
            Model_name_s = Model_name(1:(length(Model_name)-3));
            input_sig = get_param([Model_name_s '/TestData'], 'Linehandles');
            flag = 0;
            l = length(input_sig.Outport);
            for j = 1:l
                if strcmp(InputName1,get_param(input_sig.Outport(j),'Name')) == 1
                    flag = 1;
                end
            end
            if flag == 1 % Rel connect with the input signal
                InputName2 = get_param(g.Inport(2), 'SrcBlockHandle');

                add_block('Simulink/Sinks/Out1',[TestDataName '/' InputName1]);
                val = get_param(InputName2, 'Value');
                ODT = get_param(InputName2, 'OutDataTypeMode');

                if strcmp(v{1},'==')== 1 || strcmp(v{1},'Range')== 1% v{1} to char, if the constraint is '<'
                    %
                    add_block('MIL_Test/Test Data/Feature generation/Generate constant',[TestDataName '/Generate constant ' num2str(i)]);
                    set_param([TestDataName '/Generate constant ' num2str(i)], 'LinkStatus', 'none');
                    set_param([TestDataName '/Generate constant ' num2str(i)], 'Value',val);
                    set_param([TestDataName '/Generate constant ' num2str(i)], 'OutDataTypeMode',ODT);
                    fix_pos([TestDataName '/Out Bus'],[TestDataName '/Generate constant ' num2str(i)],0,100*i);
                    fix_pos([TestDataName '/Generate constant ' num2str(i)],[TestDataName '/' InputName1],150,-25);
                    add_line(TestDataName,['Generate constant ' num2str(i) '/' num2str(1)],[InputName1 '/' num2str(1)],'autorouting','on');
                    %
                    
                    elseif strcmp(v{1},'>=')== 1 || strcmp(v{1},'Range')== 1
                    add_block(['MIL_Test/Test Data/Feature generation/' sprintf('Generate \nlimited increase')],[TestDataName '/Generate increase ' num2str(i)]);
                    set_param([TestDataName '/Generate increase ' num2str(i)], 'LinkStatus', 'none');
                    set_param([TestDataName '/Generate increase ' num2str(i)], 'X0',val);
                    %set_param([TestDataName '/Generate increase ' num2str(i)], 'OutDataTypeMode',ODT);
                    fix_pos([TestDataName '/Out Bus'],[TestDataName '/Generate increase ' num2str(i)],200*i,0);
                    fix_pos([TestDataName '/Generate increase ' num2str(i)],[TestDataName '/' InputName1],150,-25);
                    add_line(TestDataName,['Generate increase ' num2str(i) '/' num2str(1)],[InputName1 '/' num2str(1)],'autorouting','on');
                    elseif strcmp(v{1},'<')== 1 || strcmp(v{1},'Range')== 1
                    add_block(['MIL_Test/Test Data/Feature generation/' sprintf('Generate \nlimited decrease')],[TestDataName '/Generate decrease ' num2str(i)]);
                    set_param([TestDataName '/Generate decrease ' num2str(i)], 'LinkStatus', 'none');
                    set_param([TestDataName '/Generate decrease ' num2str(i)], 'X0',val);%set Value for reference block
                    %set_param([TestDataName '/Generate decrease ' num2str(i)], 'OutDataTypeMode',ODT);
                    val_end = '0,000001';
                    set_param([TestDataName '/Generate decrease ' num2str(i)], 'XF',val_end);
                    fix_pos([TestDataName '/Out Bus'],[TestDataName '/Generate decrease ' num2str(i)],200*i,0);
                    fix_pos([TestDataName '/Generate decrease ' num2str(i)],[TestDataName '/' InputName1],150,-25);
                    add_line(TestDataName,['Generate decrease ' num2str(i) '/' num2str(1)],[InputName1 '/' num2str(1)],'autorouting','on');
                end
            else % Rel connect with Out signal
                f = sub{i};
                add_block('MIL_Test/Test Data/Signal comparison/Bound Precond',[TestDataName '/Bound Precond' num2str(i)]);
                set_param([TestDataName '/Bound Precond' num2str(i)], 'LinkStatus', 'none');

                % set mask Value for the Bound Precond
                v = get_param(f, 'MaskValues');
                set_param([TestDataName '/Bound Precond' num2str(i)], 'MaskValues',v);
                add_block('Simulink/Sources/Constant',[TestDataName '/<Constant>' num2str(i)]);

                g = get_param(f, 'Linehandles');
                InputName = get_param(g.Inport(2), 'SrcBlockHandle');
                val = get_param(InputName, 'Value');
                set_param([TestDataName '/<Constant>' num2str(i)], 'Value',val);%set Value for reference block

                % connect the Memory block with the Bound Precond, match the
                % Outsignal
                h1 = get_param(f,'Linehandles');
                h2 = h1.Inport(1);
                h3 = get_param(h2,'SrcPortHandle');
                sor_name = get_param(h3,'Name');
                sor_name = sor_name(2:(length(sor_name)-1));
                m = find_system(TestDataName, 'SearchDepth',1,'regexp', 'on','Name',['Memory ' sor_name]);
                m = m{1};
                fix_pos(m,[TestDataName '/Bound Precond' num2str(i)],130,0);
                fix_pos([TestDataName '/Bound Precond' num2str(i)],[TestDataName '/<Constant>' num2str(i)],-80,30);

                add_line(TestDataName,['Memory ' sor_name '/' num2str(1)],['Bound Precond' num2str(i) '/' num2str(1)],'autorouting','on');

                add_line(TestDataName,['<Constant>' num2str(i) '/' num2str(1)],['Bound Precond' num2str(i) '/' num2str(2)],'autorouting','on');
                
                    fix_pos([TestDataName '/Bound Precond' num2str(i)],[TestDataName '/Activate'],150,-25);
                    add_line(TestDataName,['Bound Precond' num2str(i) '/' num2str(1)],['Activate/' num2str(1)],'autorouting','on');
                
            end
            
            
        end
        
        
    end
    
end

%$$$$$$$--Detect true-------
feature_true = find_system(VFsName, 'SearchDepth',1,'regexp', 'on','LookUnderMasks','all','Name',sprintf('Always\nactive'));
len_true = length(feature_true);

if len_true>0
    
            Model_name_s = Model_name(1:(length(Model_name)-3));
            input_sig = get_param([Model_name_s '/TestData'], 'Linehandles');
            
            l = length(input_sig.Outport);
            for i = 1:l
                n1 = get_param(input_sig.Outport(i),'Name');
                add_block('MIL_Test/Test Data/Feature generation/Generate constant',[TestDataName '/' n1 ' random']);
                set_param([TestDataName '/' n1 ' random'], 'LinkStatus', 'none');
                set_param([TestDataName '/' n1 ' random'],'Value','0');
                fix_pos([TestDataName '/Out Bus'],[TestDataName '/' n1 ' random'],0,i*60);
                add_block('Simulink/Sinks/Out1',[TestDataName '/' n1]);
                fix_pos([TestDataName '/' n1 ' random'],[TestDataName '/' n1],200,-20);
                line_name = add_line(TestDataName,[n1 ' random/1'],[n1 '/1'],'autorouting','on');
                set_param(line_name, 'Name', n1);    
                
            end

    
end
%$$$$$$$--Detect true-------
%



%
memory_block = find_system(TestDataName, 'SearchDepth',1,'RegExp','on','Name','Memory');
memory_block_l = length(memory_block);
for k = 1 : memory_block_l
    Out_memory = get_param(memory_block{k},'Linehandles');
    if Out_memory.Outport == -1
        delete_line(Out_memory.Inport);
        delete_block(memory_block{k});
    end    
end
% IF there is no out signal delete the outbus and activate blocks
if isOut == 0
    delete_block([TestDataName '/Out Bus']);
    delete_block([TestDataName '/Activate']);
else
    del = get_param([TestDataName '/Activate'],'Linehandles');
    
    if del.Inport(1) == -1
        delete_block([TestDataName '/Activate']);
    end 
    Out_Bus_Selector = get_param([TestDataName '/Bus Selector'],'Linehandles');
    if Out_Bus_Selector.Outport == -1
        delete_line(Out_Bus_Selector.Inport);
        delete_block([TestDataName '/Bus Selector']);
    end
end




%