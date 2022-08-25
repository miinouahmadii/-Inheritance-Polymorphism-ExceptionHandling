#include "Nand_gate.h"
int Nand_gate::calculate(int _num_of_inputs,...)
{
    vector<int> nums;
    int count_1;
    va_list val;
    va_start(val,_num_of_inputs);
    for(int i=0;i<_num_of_inputs;i++)
        nums.push_back(va_arg(val,int));
    va_end(val);
    input_ids = nums;
    for(int i=0;i<nums.size();i++)
        if(nums[i]==0)
            return 1;
    return 0;
}
