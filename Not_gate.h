#ifndef NOT_H
#define NOT_H 

#include "Gate.h"


class Not_gate : public Gate{
public:
Not_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
virtual int calculate(int _num_of_inputs,...);
private:   
};
#endif