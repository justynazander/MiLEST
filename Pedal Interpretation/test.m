function []=test()
figure;
t = [10 20 30 40];
period = sum(t);
begin  = 0;
x = 4;
for i = 1:x
    if i == 1
        for j = 1:4
            if j == 1
              t1 = begin:.1:t(1);
              ts=begin;
            else
                ts = t(j-1);
                te = t(j-1)+t(j);
                t1 = ts:.1:te;
                t(j) = t(j-1)+t(j);
            end
            plot(t1,j,'--r');
            script = ['TC' num2str(j) 'V' num2str(i)];
            text(ts,j,script,...
     'HorizontalAlignment','right');
            hold on;
        end
        begin = t(4);
    else
        for j = 1:4
            if j== 1
                t = t + period;
 
                t1 = begin:.1:t(1);
            else
                ts = t(j-1);
                te = t(j);
                t1 = ts:.1:te;
            end
            plot(t1,j,'--r');
            hold on;
        end
        begin = t(4);
        
    end
    
end