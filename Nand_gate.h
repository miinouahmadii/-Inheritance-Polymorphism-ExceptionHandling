#ifndef NAND_H
#define NAND_H 

#include "Gate.h"
class Nand_gate : public Gate{
public:
Nand_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
virtual int calculate(int _num_of_inputs,...);
private:   
};
#endif