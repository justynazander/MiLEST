function [] = GenLogdata_1(source)
% automatically log the test data signal in the preconditions
load_system(source);
sys = [source '/Validation Functions'];
c = find_system(sys, 'regexp', 'on','LookUnderMasks','all','Name','Test Info');
ReqNr = length(c);
lb = length('Test Info')+1;
lg = length([source '/Validation Functions'])+2;
for i = 1:ReqNr
    if i == 1
        m=char(c{1});% the whole path and name of block
    else
        m = c{i};
    end
    l1 = length(m)-lb;
    m1 = m(lg:l1); % requirement name
    if isempty(findstr(m1,sprintf('\n'))) == 0
        m2 = strrep(m1,sprintf('\n'),' ')
    else
        m2 = m1
    end
    Precon = find_system([sys '/' m1], 'SearchDepth',2,'regexp', 'on','LookUnderMasks','all','Name','Activate');
    for j = 1:length(Precon)
        Act = Precon{j};
        ActOut = get_param(Act, 'Blocktype');
        if strcmp(ActOut, 'Outport') == 1
            R_Act = length(Act)-length('/Activate');
            F_Act = length([sys '/' m1 '/'])+1;
            ActName = Act(F_Act:R_Act); % Preconditions Name
            if isempty(findstr(ActName,sprintf('\n'))) == 0
                p1 = strrep(ActName,sprintf('\n'),' ')
            else
                p1 = ActName
            end
            logsout.TestData.(m2).(p1)
            
        end
        
    end
end