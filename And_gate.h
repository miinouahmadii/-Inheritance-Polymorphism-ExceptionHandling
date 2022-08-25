#ifndef AND_H
#define AND_H 

#include "Gate.h"
class And_gate : public Gate{
public:
    And_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
    virtual int calculate(int _num_of_inputs,...);
private:   
};
#endif