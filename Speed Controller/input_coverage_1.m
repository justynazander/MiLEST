function [] = input_coverage_1 (tar)
% statistically list all SUT input signals coverage

TARGET = tar;
load_system(tar);
disp('============================');
% when the block simout exists, then generate log file


Input1_block = [TARGET '/TestData 1'];
outline = get_param(Input1_block,'Linehandles');
outline_name = get_param(outline.Outport,'Name');
% setting the signal 'logged'
for k = 1:length(outline_name)
    in = outline.Outport(k);
    q = get_param(in,'SrcPortHandle');
        set_param(q,'DataLogging','on');
        set_param(q,'DataLoggingNameMode','Custom');
        set_param(q,'DataLoggingName',char(outline_name(k)));
   
end
sim(TARGET); %execution
disp('simulation ended------');
disp('------');
for j = 1: length(outline_name)
     data = logsout.(char(outline_name(j))).Data;
     dst_sr = get_param(outline.Outport(j),'DstBlockHandle');
     dst_sr_name = get_param(dst_sr, 'Name');
    
         if isempty(findstr(dst_sr_name, 'Signal Range')) == 0

             flag = 1; % flag for signal range block exists between Testdata and SUT
             range = get_param(dst_sr,'sr');
             second = findstr(range,',');
             sec_b = findstr(range,'[');
             sec_u = findstr(range,']');
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
                
             else
                 disp('Signal Ranges Parameter formal is not right!');
             end

         else
             flag = 0;
         end
     
     if flag == 1
         disp(['SUT Input signal : ' outline_name{j}]);
         disp(['Signal Range and Partition Point : ' range]);
         if isempty(parPoint) == 0 && upper>parPoint && lower<parPoint
             disp(['Partition Point(s) : ' num2str(parPoint)]);
             disp('Expected Signal Range is divided into:');
             disp(['{' num2str(lower) '}, ' '(' num2str(lower) ',' num2str(parPoint) '), ' '{' num2str(parPoint) '}, ' '(' num2str(parPoint) ',' num2str(upper) '),' '{' num2str(upper) '}']);
             v=[min(data) max(data)];
             point = [parPoint];
             [p partition] = get_partition(lower, upper, point,v);
             disp(['Actual Test Signal: [' num2str(min(data)) ',' num2str(max(data)) ']']);
             percent = round(p/partition*100);
             disp(['input coverage is: ' num2str(p) '/' num2str(partition) '- ' num2str(percent) '%']);
         else
             point=[0];
             v=[min(data) max(data)];
             disp(['Partition Point(s) : ' 'empty']);
             disp(['Actual Test Signal: [' num2str(min(data)) ',' num2str(max(data)) ']']);
             [p partition] = get_partition(lower, upper, point,v);
             percent = round(p/partition*100);
             disp(['input coverage is: ' num2str(p) '/' num2str(partition) '- ' num2str(percent) '%']);
             disp('/');
         end
         disp('------------------------');
     else
         disp('no Signal Range block exists !');
     end
end

  

