function [] = TestdataReqG(sys,block,tar)

%TestdataBlock = 'LCTC_vTD8_Transformation4_TC/TestData 1/';
TestdataBlock = [tar '/TestData 1/'];
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
    
    Testdata_Preconditions_G(sys,m1,tar);
    %set the lines name according to the Outport name
    
%&&&&&&&
% for i>1
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
    Testdata_Preconditions_G(sys,m1,tar);
end
%$$$$$$$$$$


