#ifndef GATE_H
#define GATE_H 
#include <vector>
#include <string>
using namespace std;
class Gate{
public:
Gate(int _num_of_inputs,int _output_id);
int get_number_of_gate_inputs(){ return num_of_inputs;}
int get_output_id(){return  output_id;}
string get_gate_type(){return gate_type;}
vector<int> get_input_ids(){return input_ids;}
virtual int calculate(int _num_of_inputs,...)=0;
protected:
int num_of_inputs;
int output_id;
string gate_type;
vector<int> input_ids;
};
#endif