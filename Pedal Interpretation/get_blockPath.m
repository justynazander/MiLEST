function [Model_name] = get_blockPath()

% return the model's name 
path = get_param(gcb,'Parent');
if length(findstr(path, '/'))>=1
    po = findstr(path, '/')-1;
    Model_name_1 = path(1:po);
else
    Model_name_1 = path;
    
end

Model_name = [Model_name_1 '/SUT/Test_quaternion'];