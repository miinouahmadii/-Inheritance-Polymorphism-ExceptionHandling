#ifndef CIRCUIT_H
#define CIRCUIT_H 
#include <vector>
#include <string>
#include "Gate.h"
#include "wire.h"
class Circuit{
public:
void add_gate_to_circuit(GateType g_type,int num_of_inputs,int output_id,...);
void connect(int inp,int oup);
void print_gate_output(int oup);
void put_value_on_gate_input(int gate_id, int value){};
Gate* find_gate(int id);
bool is_in_gates(int id);
private:
vector <Gate*> Gates;
vector <wire*> wires;
};
#endif