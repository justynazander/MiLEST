function [] = input_coverage (tar)
% report input signals partitions
TARGET = tar;
Input1_block = [TARGET '/TestData'];
outline = get_param(Input1_block,'Linehandles');
outline_name = get_param(outline.Outport,'Name');
for j = 1: length(outline_name)
         
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
                        %break;
                     else
                         disp('Signal Ranges Parameter formal is not right!');
                     end

                 else
                     flag = 0;
                 end
             end
             disp(['SUT Input signal : ' outline_name{j}]);
             disp(['Signal Range : ' range]);
             if upper>0 && lower<0
                 disp(['Partition Point(s) : ' '0']);
                 disp('Signal Range is divided into:');
                 disp(['domain : (' num2str(lower) ',0)']);
                 disp('According to the rule: ');
                 disp('Variant(1)=(lower,(lower+(abs(PartitionPoint-lower)*10%))');
                 v1 = lower + (0-lower)*0.1;
                 disp(['V1 = (' num2str(lower) ',' num2str(v1) ')']);
                 disp('According to the rule: ');
                 disp('Variant(2)=((PartitionPoint-(abs(PartitionPoint-lower)*10%)),PartitionPoint)');
                 v2 = 0 - (0-lower)*0.1;
                 disp(['V2 = (' num2str(v2) ',' num2str(0) ')']);
                 disp('/');
                 disp(['domain : (0,' num2str(upper) ')']);
                 disp('According to the rule: ');
                 disp('Variant(3)=(PartitionPoint,(PartitionPoint+(abs(PartitionPoint-upper)*10%))');
                 v3 = 0 + (upper-0)*0.1;
                 disp(['V3 = (' num2str(0) ',' num2str(v3) ')']);
               
                 disp('According to the rule: ');
                 disp('Variant(4)=((upper-(abs(PartitionPoint-upper)*10%)),upper)');
                 v4 = upper - (upper-0)*0.1;
                 disp(['V4 = (' num2str(v4) ',' num2str(upper) ')']);
             else
                 disp(['Partition Point(s) : ' 'EMPTY']);
                 
                 disp('According to the rule: ');
                 disp('Variant(1)=(lower,(lower+(abs(upper-lower)*10%))');
                 v1 = lower + (upper-lower)*0.1;
                 disp(['V1 = (' num2str(lower) ',' num2str(v1) ')']);
                 disp('According to the rule: ');
                 disp('Variant(2)=((upper-(abs(PartitionPoint-lower)*10%)),upper)');
                 v2 = upper - (upper-lower)*0.1;
                 disp(['V2 = (' num2str(v2) ',' num2str(upper) ')']);
                 disp('/');
             end
             disp('------------------------');
             
end