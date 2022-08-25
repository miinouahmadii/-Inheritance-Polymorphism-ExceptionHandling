#ifndef OR_H
#define OR_H

#include "Gate.h"
class Or_gate : public Gate{
public:
Or_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
virtual int calculate(int _num_of_inputs,...);
private:   
};
#endif