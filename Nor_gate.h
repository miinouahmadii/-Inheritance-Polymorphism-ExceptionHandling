#ifndef NOR_H
#define NOR_H 

#include "Gate.h"
class Nor_gate : public Gate{
public:
Nor_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
virtual int calculate(int _num_of_inputs,...);
private:   
};
#endif