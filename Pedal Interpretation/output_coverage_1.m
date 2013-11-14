function [] = output_coverage_1 (tar)
% statistically list all SUT output signals coverage

TARGET = tar;

load_system(tar);
file = find_system(TARGET, 'regexp', 'on','Name','To File');

disp('============================');
% when the block simout exists, then generate log file
if ~isempty(file)
    sim(TARGET); %execution
    [x y]=test_log(TARGET);
    
    Input1_block = [TARGET '/' 'To File'];
    
    outline = get_param(Input1_block,'Linehandles');
    %outline = outline1.Inport;
    outline_name = get_param(outline.Inport,'Name');
    
    % check if a SR block exists outside of SUT
    c = findstr(outline_name, ',');

    if ~isempty(c) % more than one signal in one line
        sig_nr = length(c)+1;
        a = outline_name;
    else % one signal in one line
        sig_nr = 1;
        a = outline_name;
    end
           
       
        %
        
         % the number of signals in one line
            % the output signals in a line will distinguish each other
            % using  ','
            % the output signal cannot be the form like '<T1,T2>'
            % matlab will ignore such form
         dst_sr = get_param(outline.Inport(1),'SrcBlockHandle');
         partition_l = get_param(dst_sr, 'Linehandles');
         partition_b = get_param(partition_l.Inport(1),'SrcBlockHandle');
         partition_1 = get_param(partition_b,'sr');
         partition_p = partition_1(2:(end-1));
         par_dot = findstr(partition_p,',');
         
         
         range_1 = get_param(dst_sr,'sr');
         range = range_1(2:(end-1));
         second = findstr(range,',');
           
    for i = 1:sig_nr  % 
       
         sigOut_name = a;
        
         %
         s1 = findstr(outline_name, ',');
                if i == 1
                    sigOut_name = a(1:(s1(1)-1));
                    lower = str2double(range(2:(second(1)-1)));
                    upper = str2double(range((second(1)+1):(second(2)-2)));
                   
                    point = str2num(partition_p(1:(par_dot(1)-1)));
                elseif i == sig_nr
                    sigOut_name = a((s1(sig_nr-1)+1):end);
                    sig_nr_r = 2*sig_nr-1;
                    lower = str2double(range((second(sig_nr_r-1)+2):(second(sig_nr_r)-1)));
                    upper = str2double(range((second(sig_nr_r)+1):(end-1)));
                     
                    point = str2num(partition_p((par_dot(i-1)+1):end));
                else
                    sigOut_name = a((s1(i-1)+1):(s1(i)-1));
                    sig_nr_r = 2*i-1;
                    lower = str2double(range((second(sig_nr_r-1)+2):(second(sig_nr_r)-1)));
                    upper = str2double(range((second(sig_nr_r)+1):(second(sig_nr_r+1)-2)));
                    

                    point = str2num(partition_p((par_dot(i-1)+1):(par_dot(i)-1)));
                end
                
           
         %
         
        v = [x(i) y(i)];
        [p partition] = get_partition(lower, upper, point,v);
        disp(['The SUT output signal: ' sigOut_name ' Signal Range : ' '[' num2str(lower) ',' num2str(upper) ']']);
        if isempty(point) == 1
           disp(['The SUT output signal: ' sigOut_name ' partition point(s) : ' 'EMPTY']);
        else
           disp(['The SUT output signal: ' sigOut_name ' partition point(s) : ' '{' num2str(point) '}']);
        end
        disp(['Actual Output Signal Value: [' num2str(x(i)) ',' num2str(y(i)) ']']);
        percent = round(p/partition*100);
        disp(['The SUT output signal: ' sigOut_name ' testing coverage is: ' num2str(p) '/' num2str(partition) '- ' num2str(percent) '%']);
        disp('----------------------------------------------');

    end
end
%         elseif sig_nr > 1 % more than one signal in one line
%             s1 = findstr(outline_name{j}, ',');
%             dst_sr = get_param(outline.Inport(j),'SrcBlockHandle');
%             dst_sr_name = get_param(dst_sr, 'Name');
%             
%              %sigOut_name = a;
%             
%              
%                  if isempty(findstr(dst_sr_name, 'Signal Range')) == 0
%                      
%                      flag = 1; % flag for signal range block exists between Testdata and SUT
%                      range = get_param(dst_sr,'sr');
%                      second = findstr(range,',');
%                      
%                  else
%                      flag = 0;
%                  end
%              for x = 1:sig_nr
%                 if x == 1
%                     sigOut_name = a(1:(s1(1)-1));
%                     lower = str2double(range(2:(second(1)-1)));
%                     upper = str2double(range((second(1)+1):(second(2)-2)));
%                 elseif x == sig_nr
%                     sigOut_name = a((s1(sig_nr)+1):end);
%                     sig_nr_r = 2*sig_nr-1;
%                     lower = str2double(range((second(sig_nr_r-1)+2):(second(sig_nr_r)-1)));
%                     upper = str2double(range((second(sig_nr_r)+1):(end-1)));
%                 else
%                     sigOut_name = a((s1(sig_nr-1)+1):(s1(sig_nr)-1));
%                     sig_nr_r = 2*sig_nr-1;
%                     lower = str2double(range((second(sig_nr_r-1)+2):(second(sig_nr_r)-1)));
%                     upper = str2double(range((second(sig_nr_r)+1):(second(sig_nr_r+1)-2)));
%                 end
%                 if flag == 1
%                     [p partition] = get_partition(lower, upper, point,v);
%                     disp(['The output signal: ' sigOut_name ' coverage is = ' p '/' partition]);
%                 end
%             end
%         end
%     
% end