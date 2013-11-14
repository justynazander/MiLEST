function [variants_nr] = GenConstVar_Single_D (is_increase, tar, InputName, ODT,duration_tick)


      %line_out = get_param(is_increase{i},'Linehandles');
      %dst_block = get_param(line_out.Outport,'DstBlockHandle');
%       lower = num2str(input(['please input lower boundary of_' InputName ':']));
%       upper = num2str(input(['please input upper boundary of_' InputName ':']));
%duration_tick = '2000';
tar_l = length(tar);
SOURCE = tar(1:(tar_l-3));
fixstep = get_param(SOURCE,'FixedStep');
duration = num2str(str2num(duration_tick) * str2num(fixstep));

if strcmp(InputName,'v_Fzg') == 1
    lower = '-10';
    upper = '70';
elseif strcmp(InputName,'phi_Acc') == 1 ||strcmp(InputName,'phi_Brake') == 1
    lower = '0';
    upper = '100';
else
    lower = num2str(input(['please input lower boundary of_' InputName ':']));
    upper = num2str(input(['please input upper boundary of_' InputName ':']));
end
  if str2double(lower) <= str2double(upper)
      l = get_param([is_increase '/In1'], 'Linehandles');
      delete_line(l.Outport);
      delete_block([is_increase '/In1']);
      set_param([is_increase '/Out1'],'Name', InputName);
      add_block('Simulink/Signal Routing/Multiport Switch',[is_increase '/switch']);
      fix_pos([is_increase '/' InputName],[is_increase '/switch'],-70,-25);
      add_line(is_increase,['switch' '/' num2str(1)],[InputName '/' num2str(1)],'autorouting','on');
      %   
      sig_name = InputName;
      sig_datatype_l = lower;
      sig_datatype_u = upper; %char
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
                         if isempty(second) == 0
                            lower = str2double(range(2:(second-1)));
                            upper = str2double(range((second+1):(length(range)-1)));
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
                     if isempty(second) == 0
                        lower = str2double(range(2:(second-1)));
                        upper = str2double(range((second+1):(length(range)-1)));
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
        
      %judge 'zero' between the datatype?
      if (str2double(sig_datatype_l)>=0 || str2double(sig_datatype_u)<=0) && flag == 0
          
          
          %TestDataName = get_param(is_increase{i}, 'Parent');
          add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)]);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'X0', sig_datatype_l);
          %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'T', duration);
          fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
          add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)]);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'X0', sig_datatype_u);
          %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'OutDataTypeMode', ODT);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'T', duration);
          fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
          variants_nr = 2;
          set_param([is_increase '/switch'], 'Inputs', '2');
          add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
          add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
          GenVarSequence_1(TestDataName, 2);
      end
      if (str2double(sig_datatype_l)>=0 || str2double(sig_datatype_u)<=0) && flag == 1
          
          
          if lower >= str2double(sig_datatype_l) && upper <= str2double(sig_datatype_u)
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(lower));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(upper));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
              variants_nr = 2;
              set_param([is_increase '/switch'], 'Inputs', '2');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
              GenVarSequence_1(TestDataName, 2);
          else
              disp('Signal Ranges Parameter lower is smaller than data domain below limit or upper larger than data domain upper limit!');
          end
      end
      if str2double(sig_datatype_l)<0 && str2double(sig_datatype_u)>0 && flag == 0
          
          add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)]);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'X0', sig_datatype_l);
          %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'T',duration);
          fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
          add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)]);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'X0', sig_datatype_u);
          %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'OutDataTypeMode', ODT);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'T', duration);
          fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],i*(-200),-120);
          add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)]);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'LinkStatus', 'none');
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'X0', '0');
          %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'OutDataTypeMode', ODT);
          set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'T', duration);
          fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)],i*(-200),-240);
          variants_nr = 3;
          set_param([is_increase '/switch'], 'Inputs', '3');
          add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
          add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
          add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant3 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(4)],'autorouting','on');
          GenVarSequence_1(TestDataName, 3);
      end
      if str2double(sig_datatype_l)<0 && str2double(sig_datatype_u)>0 && flag == 1
         if lower >= str2double(sig_datatype_l)&&upper <= str2double(sig_datatype_u)
          if lower<0 && upper > 0 
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(lower));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(upper));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],i*(-200),-120);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'X0', '0');
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant3 ') num2str(i)],i*(-200),-240);
              variants_nr = 3;
              set_param([is_increase '/switch'], 'Inputs', '3');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant3 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(4)],'autorouting','on');
              GenVarSequence_1(TestDataName, 3);
          else
              
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(lower));
              %set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
              add_block('MIL_Test/Test Data/Feature generation/Generate timed constant',[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(upper));
             % set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'OutDataTypeMode', ODT);
              set_param([TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nconstant\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
              variants_nr = 2;
              set_param([is_increase '/switch'], 'Inputs', '2');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nconstant\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
              GenVarSequence_1(TestDataName, 2);
          end
         else
              disp('SR lower X0 is lower or upper greater than Boundary limit!');
         end
      end
  else
      disp('Data Boundary lower is greater than upper!');
  end