function [s,u] = test_log (tar)

sim(tar);
load('v_Vhcl')
nr = size(v_Vhcl);
nr_sig = nr(1)-1; % the number of signal

col = v_Vhcl(2,:);
u = max(col);
s = min(col);