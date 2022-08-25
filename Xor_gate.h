#ifndef XOR_H
#define XOR_H 

#include "Gate.h"

class Xor_gate : public Gate{
public:
Xor_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
virtual int calculate(int _num_of_inputs,...);
private:   
};
#endif