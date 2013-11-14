function [time_exe, vr_max] = TestdataReqG(sys,block,tar,duration_tick)
% requirement level transformation
%load_system(sys);
TestdataBlock = [tar '/TestData 1/'];
vr_max = [1];
TCD_Previous = 0;
c = find_system(sys, 'regexp', 'on','LookUnderMasks','all','Name',block);
l = length(c);
lb = length(block)+1;
lg = length(char(sys))+2;
% for i = 1
m=char(c{1});% the whole path and name of block
l1 = length(m)-lb;
m1= m(lg:l1); % the name of requirement

set_param([TestdataBlock '<Requirement name>'], 'Name', m1);
% redesign the sketch of the requirement level
    lines = get_param([TestdataBlock m1 '/<Preconditions name>'],'Linehandles');
    delete_line(lines.Outport);
    delete_line(lines.Inport);
    InitOutLine = get_param([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation')],'Linehandles');
    delete_line(InitOutLine.Outport);
%---for count the Preconditions
    
    [t1 p_nr vr_max_1] = Testdata_Preconditions_G(sys,m1,tar,duration_tick,TCD_Previous);
    vr_max = [vr_max vr_max_1];
    %set the lines name according to the Outport name
    t = [t1];
    max_pre = [p_nr];
    TCD_Previous = t1;
%&&&&&&&
% for i>1
if l >2
    for i = 2:l
        m = c{i};
        l1 = length(m)-lb;
        m1= m(lg:l1);
        set_param([TestdataBlock '<Requirement name>' num2str(i)], 'Name', m1);
    %---for count the Preconditions 
        lines = get_param([TestdataBlock m1 '/<Preconditions name>'],'Linehandles');
        delete_line(lines.Outport);
        delete_line(lines.Inport);
        InitOutLine = get_param([TestdataBlock m1 sprintf('/Initialisation &\nStabilisation')],'Linehandles');
        delete_line(InitOutLine.Outport);
        [t2 p_nr vr_max_1] = Testdata_Preconditions_G(sys,m1,tar,duration_tick,TCD_Previous);
        t = [t t2];
        max_pre = [max_pre p_nr];
        vr_max = [vr_max vr_max_1];
        TCD_Previous = sum(t);
    end
end
%$$$$$$$$$$
time_exe = t; 
pre = max(max_pre);
%vr_max = max(vr_max);
