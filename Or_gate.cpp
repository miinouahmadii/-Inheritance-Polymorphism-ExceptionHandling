#include"Or_gate.h"
int Or_gate::calculate(int _num_of_inputs,...)
{
    vector<int> nums;
    va_list val;
    va_start(val,_num_of_inputs);
    for(int i=0;i<_num_of_inputs;i++)
        nums.push_back(va_arg(val,int));
    va_end(val);
    input_ids = nums;
    for(int i=0;i<nums.size();i++)
        if(nums[i]==1)
            return 1;
    return 0;
}
