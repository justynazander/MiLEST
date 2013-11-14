function [variants_nr] = GenConstVar_Single_D_1 (is_increase, tar, InputName, ODT,duration_tick)

% Partitioning the 'Generate Constant' feature signal
% Consistent with the 'Detect Constant' in Validation Functions
% the Function feeds back the generated variants' number

tar_l = length(tar);
SOURCE = tar(1:(tar_l-3));
fixstep = get_param(SOURCE,'FixedStep');
duration = num2str(str2num(duration_tick) * str2num(fixstep));

      l = get_param([is_increase '/In1'], 'Linehandles');
      delete_line(l.Outport);
      delete_block([is_increase '/In1']);
      set_param([is_increase '/Out1'],'Name', InputName);
      add_block('Simulink/Signal Routing/Multiport Switch',[is_increase '/switch']);
      fix_pos([is_increase '/' InputName],[is_increase '/switch'],-70,-25);
      add_line(is_increase,['switch' '/' num2str(1)],[InputName '/' num2str(1)],'autorouting','on');
      %   
      sig_name = InputName;
      
      %search signal range exist?
      TARGET = tar;
      Input1_block = [TARGET '/TestData 1'];
      outline = get_param(Input1_block,'Linehandles');
      outline_name = get_param(outline.Outport,'Name');
      TestDataName = is_increase;
      i = 1;
      
      for j = 1: length(outline_name)
         
         if strcmp(outline_name{j},sig_name) == 1
             dst_sr = get_param(outline.Outport(j),'DstBlockHandle');
             dst_sr_name = get_param(dst_sr, 'Name');
             
             if ischar(dst_sr_name) == 0 % more than 1 block connect with signal
                 for k = 1:length(dst_sr_name)
                     
                     if isempty(findstr(dst_sr_name{k}, 'Signal Range')) == 0
                         
                         flag = 1; % flag for signal range block exists between Testdata and SUT
                         range = get_param(dst_sr(k),'sr');
                         second = findstr(range,',');
                         sec_u = findstr(range,']');
                         sec_b = findstr(range,'[');
                         par = findstr(range,'{');
                         par_e = findstr(range,'}');
                        % par_s = findstr(range,';');
                         if isempty(second) == 0
                            lower = str2double(range((sec_b+1):(second-1)));
                            upper = str2double(range((second+1):(sec_u-1)));
                            if par+1 == par_e
                                parPoint = []; % no partition point
                            else
                                parPoint = str2double(range((par+1):(par_e-1)));
                            end
                            
                            break;
                         else
                             disp('Signal Ranges Parameter formal is not right!');
                         end

                     else
                         flag = 0;
                     end
                 end
             else % just one block connect with signal
                 if isempty(findstr(dst_sr_name, 'Signal Range')) == 0
                     
                     flag = 1; % flag for signal range block exists between Testdata and SUT
                     range = get_param(dst_sr,'sr');
                     second = findstr(range,',');
                     sec_u = findstr(range,']');
                     sec_b = findstr(range,'[');
                     par = findstr(range,'{');
                     par_e = findstr(range,'}');
                     if isempty(second) == 0
                        lower = str2double(range((sec_b+1):(second-1)));
                        upper = str2double(range((second+1):(sec_u-1)));
                        if par+1 == par_e
                                parPoint = []; % no partition point
                        else
                            parPoint = str2double(range((par+1):(par_e-1)));
                        end
                        break;
                     else
                         disp('Signal Ranges Parameter formal is not right!');
                     end

                 else
                     flag = 0;
                 end
             end
             
         end
      end
      sig_datatype_l = lower;
      sig_datatype_u = upper; 
      %judge 'zero' between the datatype?
      if flag == 1
         if isempty(parPoint) == 0
          if sig_datatype_l<parPoint && sig_datatype_u>parPoint
        
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(sig_datatype_l));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],i*(-300),0);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(sig_datatype_l/2));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],0,70);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'X0', '0');
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)],0,70);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant4 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant4 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant4 ') num2str(i)], 'X0', num2str(sig_datatype_u/2));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant4 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant4 ') num2str(i)],0,70);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant5 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant5 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant5 ') num2str(i)], 'X0', num2str(sig_datatype_u));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant5 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant4 ') num2str(i)],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant5 ') num2str(i)],0,70);
              variants_nr = 5;
              set_param([is_increase '/switch'], 'Inputs', '5');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant3 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(4)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant4 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(5)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant5 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(6)],'autorouting','on');
              GenVarSequence_1(TestDataName, 5);
           
          else
              
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(lower));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(lower+(upper-lower)/2));
             % set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'LinkStatus', 'none');
             
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'X0', num2str(upper));
              
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)],i*(-200),-160);
              variants_nr = 3;
              set_param([is_increase '/switch'], 'Inputs', '3');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant3 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(4)],'autorouting','on');
              GenVarSequence_1(TestDataName, 3);
          
          end
         else
             add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(lower));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],i*(-300),0);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(lower+(upper-lower)/2));
             % set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],0,70);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'LinkStatus', 'none');
             
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'X0', num2str(upper));
              
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)],0,70);
              variants_nr = 3;
              set_param([is_increase '/switch'], 'Inputs', '3');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant3 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(4)],'autorouting','on');
              GenVarSequence_1(TestDataName, 3);
         end
      else
         disp('error3: no Signal Range exists')
      end
      
      
      
          
         
    
      