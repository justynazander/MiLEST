function [par,partition] = get_partition (lower, upper, point,v)
% count the number of partition
sort(point);
partition = 1;
par = 1;
array = [point lower upper];
sort(array);
if length(point)>0
    
    for i = 1:length(point)
        if i < length(point)
            if point(i) == point(i+1)
                partition = 0; %indicate error
                disp(['error1: duplicated point value ' num2str(point(i))]);
                break;
            end
            
        end
        if point(i)> lower && point(i) < upper
            partition = partition + 1;
             
        else
            
            partition = 0; %indicate error
            disp(['error2: transition point value ' num2str(point(i)) ' is out of range']);
            break;
        end
        if point(i)> v(1) && point(i) < v(2)
           par = par+1;
        end
    end
end