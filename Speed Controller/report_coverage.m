function [] = report_coverage (tar)
% generate a value coverage report for output signal

TARGET = tar;
point = [5 20 80];
load_system(tar);
file = find_system(TARGET, 'regexp', 'on','Name','To File');
% when the block simout exists, then generate log file
if ~isempty(file)
    %sim(TARGET); %execution
    [x y]=test_log(TARGET);
    v = [x y];
    Input1_block = [TARGET '/' 'To File'];
    
    outline = get_param(Input1_block,'Linehandles');
    %outline = outline1.Inport;
    outline_name = get_param(outline.Inport,'Name');
    
    % check if a SR block exists outside of SUT
    for j = 1: length(outline)
        c = findstr(outline_name, ',');
        if length(outline) == 1
            if ~isempty(c) % more than one signal in one line
                sig_nr = length(findstr(c, ','))+1;
                a = outline_name;
            else % one signal in one line
                sig_nr = 1;
                a = outline_name;
            end
           
        else
            if ~isempty(c) % more than one signal in one line
                sig_nr = length(findstr(outline_name{j}, ','))+1;
                a = outline_name{j};
            else % one signal in one line
                sig_nr = 1;
                a = outline_name;
            end
        end
        %
        
         % the number of signals in one line
            % the output signals in a line will distinguish each other
            % using a ','
            % the output signal cannot be the form like '<T1,T2>'
            % matlab will ignore such form
            
        if sig_nr == 1 % just one signal in a line
           %if strcmp(a,sig_name) == 1
             sigOut_name = a;
             dst_sr = get_param(outline.Inport(j),'SrcBlockHandle');
             dst_sr_name = get_param(dst_sr, 'Name');
             
             range = get_param(dst_sr,'sr');
             second = findstr(range,',');
             if isempty(second) == 0
                lower = str2double(range(2:(second-1)));
                upper = str2double(range((second+1):(length(range)-1)));

             else
                 disp('Signal Ranges Parameter formal is not right!');
             end

            [p partition] = get_partition(lower, upper, point,v);
            disp(['The output signal: ' sigOut_name ' testing coverage is: ' num2str(p) '/' num2str(partition)]);
           
           %end
        elseif sig_nr > 1 % more than one signal in one line
            s1 = findstr(outline_name{j}, ',');
            dst_sr = get_param(outline.Inport(j),'SrcBlockHandle');
            dst_sr_name = get_param(dst_sr, 'Name');
            
             %sigOut_name = a;
            
             
                 if isempty(findstr(dst_sr_name, 'Signal Range')) == 0
                     
                     flag = 1; % flag for signal range block exists between Testdata and SUT
                     range = get_param(dst_sr,'sr');
                     second = findstr(range,',');
                     
                 else
                     flag = 0;
                 end
             for x = 1:sig_nr
                if x == 1
                    sigOut_name = a(1:(s1(1)-1));
                    lower = str2double(range(2:(second(1)-1)));
                    upper = str2double(range((second(1)+1):(second(2)-2)));
                elseif x == sig_nr
                    sigOut_name = a((s1(sig_nr)+1):end);
                    sig_nr_r = 2*sig_nr-1;
                    lower = str2double(range((second(sig_nr_r-1)+2):(second(sig_nr_r)-1)));
                    upper = str2double(range((second(sig_nr_r)+1):(end-1)));
                else
                    sigOut_name = a((s1(sig_nr-1)+1):(s1(sig_nr)-1));
                    sig_nr_r = 2*sig_nr-1;
                    lower = str2double(range((second(sig_nr_r-1)+2):(second(sig_nr_r)-1)));
                    upper = str2double(range((second(sig_nr_r)+1):(second(sig_nr_r+1)-2)));
                end
                if flag == 1
                    [p partition] = get_partition(lower, upper, point,v);
                    disp(['The output signal: ' sigOut_name ' coverage is = ' p '/' partition]);
                end
            end
        end
        
    
    end
    
end