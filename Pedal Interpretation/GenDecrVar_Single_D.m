function [variants_nr] = GenDecrVar_Single_D (is_increase, tar, InputName,duration_tick)
% Partitioning the 'Generate Decrease' feature signal
% Consistent with the 'Detect Decrease' in Validation Functions
% the Function feeds back the generated variants' number


tar_l = length(tar);
SOURCE = tar(1:(tar_l-3));
fixstep = get_param(SOURCE,'FixedStep');
duration = num2str(str2num(duration_tick) * str2num(fixstep));

% if strcmp(InputName,'v_Fzg') == 1
%     lower = '-10';
%     upper = '70';
% elseif strcmp(InputName,'phi_Acc') == 1 ||strcmp(InputName,'phi_Brake') == 1
%     lower = '0';
%     upper = '100';
% else
%     lower = num2str(input(['please input lower boundary of_' InputName ':']));
%     upper = num2str(input(['please input upper boundary of_' InputName ':']));
% end
%  if str2double(lower) <= str2double(upper)
      l = get_param([is_increase '/In1'], 'Linehandles');
      delete_line(l.Outport);
      delete_block([is_increase '/In1']);
      set_param([is_increase '/Out1'],'Name', InputName);
      add_block('Simulink/Signal Routing/Multiport Switch',[is_increase '/switch']);
      fix_pos([is_increase '/' InputName],[is_increase '/switch'],-70,-25);
      add_line(is_increase,['switch' '/' num2str(1)],[InputName '/' num2str(1)],'autorouting','on');
      %   
      sig_name = InputName;
%       sig_datatype_l = lower;
%       sig_datatype_u = upper; %char
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
              if ischar(dst_sr_name) == 0
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
        
      %judge 'zero' between the datatype?
%       if (str2double(sig_datatype_l)>=0 || str2double(sig_datatype_u)<=0) && flag == 0
%           
%           r = str2double(sig_datatype_u) - str2double(sig_datatype_l);
%           pi = 0.1*r;
%           follower_l = str2double(sig_datatype_l) + pi;
%           follower_u = str2double(sig_datatype_u) - pi;
%           %TestDataName = get_param(is_increase{i}, 'Parent');
%           add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)]);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(follower_l));
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'XF', sig_datatype_l);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'T', duration);
%           fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
%           add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)]);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'XF', num2str(follower_u));
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'X0', sig_datatype_u);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'T', duration);
%           fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
%           variants_nr = 2;
%           set_param([is_increase '/switch'], 'Inputs', '2');
%           add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
%           add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
%           GenVarSequence_1(TestDataName, 2);
%       end
      if flag == 1
          if isempty(parPoint) == 1 || parPoint >= upper || parPoint <= lower
              r = upper - lower;
              pi = 0.1*r;
              follower_l = lower + pi;
              follower_u = upper - pi;
              %TestDataName = get_param(is_increase{i}, 'Parent');
              add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'XF', num2str(lower));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(follower_l));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
              add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'XF', num2str(follower_u));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(upper));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
              variants_nr = 2;
              set_param([is_increase '/switch'], 'Inputs', '2');
              add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
              GenVarSequence_1(TestDataName, 2);
          elseif isempty(parPoint) == 0 && parPoint < upper && parPoint > lower
              r1 = parPoint - lower;
              r2 = upper - parPoint;
              pi1 = 0.1*r1;
              pi2 = 0.1*r2;
              follower_l = lower + pi1;
              zero_l = parPoint - pi1;
              zero_u = parPoint + pi2;
              follower_u = upper - pi2;
              %TestDataName = get_param(is_increase{i}, 'Parent');
              add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'XF', num2str(lower));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(follower_l));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
              add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'XF', num2str(zero_l));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(parPoint));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
              add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'XF', num2str(parPoint));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'X0', num2str(zero_u));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)],i*(-200),-160);
              add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)]);
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'LinkStatus', 'none');
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'XF', num2str(follower_u));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'X0', num2str(upper));
              set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'T', duration);
              fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)],i*(-200),-240);
              variants_nr = 4;
              set_param([is_increase '/switch'], 'Inputs', '4');
              add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');

              add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(5)],'autorouting','on');
              add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(4)],'autorouting','on');
              GenVarSequence_1(TestDataName, 4);
          end
          else
           disp('no Signal Range block exists !');
      end
%       if str2double(sig_datatype_l)<0 && str2double(sig_datatype_u)>0 && flag == 0
%           r1 =  0 - str2double(sig_datatype_l);
%           r2 = str2double(sig_datatype_u);
%           pi1 = 0.1*r1;
%           pi2 = 0.1*r2;
%           follower_l = str2double(sig_datatype_l) + pi1;
%           zero_l = 0 - pi1;
%           zero_u = 0 + pi2;
%           follower_u = str2double(sig_datatype_u) - pi2;
%           %TestDataName = get_param(is_increase{i}, 'Parent');
%           add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)]);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'XF', sig_datatype_l);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(follower_l));
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'T', duration);
%           fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
%           add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)]);
%           
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'XF', num2str(zero_l));
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'X0', '0');
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'T', duration);
%           fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)],i*(-200),-100);
%           add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)]);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'LinkStatus', 'none');
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'XF', '0');
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'X0', num2str(zero_u));
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'T', duration);
%           fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)],i*(-200),-200);
%           add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)]);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'LinkStatus', 'none');
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'XF', num2str(follower_u));
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'X0', sig_datatype_u);
%           set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'T', duration);
%           fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)],i*(-200),-300);
%           variants_nr = 4;
%           set_param([is_increase '/switch'], 'Inputs', '4');
%           add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
%           add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
%           
%           add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(5)],'autorouting','on');
%           add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(4)],'autorouting','on');
%           GenVarSequence_1(TestDataName, 4);
%       end
%       if str2double(sig_datatype_l)<0 && str2double(sig_datatype_u)>0 && flag == 1
%          if lower >= str2double(sig_datatype_l)&&upper <= str2double(sig_datatype_u)
%           if lower<0 && upper > 0 
%               r1 =  0 - lower;
%               r2 = upper;
%               pi1 = 0.1*r1;
%               pi2 = 0.1*r2;
%               follower_l = lower + pi1;
%               zero_l = 0 - pi1;
%               zero_u = 0 + pi2;
%               follower_u = upper - pi2;
%               %TestDataName = get_param(is_increase{i}, 'Parent');
%               add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)]);
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'XF', num2str(lower));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(follower_l));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'T', duration);
%               fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
%               add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)]);
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'XF', num2str(zero_l));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'X0', '0');
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'T', duration);
%               fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
%               add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)]);
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'LinkStatus', 'none');
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'XF', '0');
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'X0', num2str(zero_u));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)], 'T', duration);
%               fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i)],i*(-200),-160);
%               add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)]);
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'LinkStatus', 'none');
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'XF', num2str(follower_u));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'X0', num2str(upper));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)], 'T', duration);
%               fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i)],i*(-200),-240);
%               variants_nr = 4;
%               set_param([is_increase '/switch'], 'Inputs', '4');
%               add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
%               add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
% 
%               add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition2 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(5)],'autorouting','on');
%               add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition2 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(4)],'autorouting','on');
%               GenVarSequence_1(TestDataName, 4);
%           else
%               
%               r = upper - lower;
%               pi = 0.1*r;
%               follower_l = lower + pi;
%               follower_u = upper - pi;
%               %TestDataName = get_param(is_increase{i}, 'Parent');
%               add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)]);
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'LinkStatus', 'none');
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'XF', num2str(lower));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'X0', num2str(follower_l));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)], 'T', duration);
%               fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i)],i*(-200),0);
%               add_block(['MIL_Test/Test Data/Feature generation/' 'Generate timed limited decrease'],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)]);
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'LinkStatus', 'none');
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'XF', num2str(follower_u));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'X0', num2str(upper));
%               set_param([TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)], 'T', duration);
%               fix_pos([TestDataName '/' sig_name],[TestDataName sprintf('/Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i)],i*(-200),-80);
%               variants_nr = 2;
%               set_param([is_increase '/switch'], 'Inputs', '2');
%               add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant2 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(3)],'autorouting','on');
%               add_line(TestDataName,[sprintf('Generate \nlimited decrease\nfor partition1 variant1 ') num2str(i) '/' num2str(1)],['switch' '/' num2str(2)],'autorouting','on');
%               GenVarSequence_1(TestDataName, 2);
%           end
%          else
%               disp('SR lower value is lower or upper greater than Boundary limit!');
%          end
%       end
%   else
%       disp('Data Boundary lower is greater than upper!');
%   end