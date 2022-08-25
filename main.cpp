#include <iostream>
#include <string>
#include <vector>
#include "Gate.h"
#include "And_gate.h"
#include "Or_gate.h"
#include "Not_gate.h"
#include "Xor_gate.h"
#include "Nand_gate.h"
#include "Nor_gate.h"
#include "wire.h"
#include "Circuit.h"
using namespace std;

enum GateType {And,Or,Not,Xor,Nand,Nor};

// class Gate{
// public:
// Gate(int _num_of_inputs,int _output_id):num_of_inputs(_num_of_inputs),output_id(_output_id){}
// int get_number_of_gate_inputs(){ return num_of_inputs;}
// int get_output_id(){return  output_id;}
// string get_gate_type(){return gate_type;}
// vector<int> get_input_ids(){
//     return input_ids;
// }
// virtual int calculate(int _num_of_inputs,...)=0;
// protected:
// int num_of_inputs;
// int output_id;
// string gate_type;
// vector<int> input_ids;
// };

// class And_gate : public Gate{
// public:
// And_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
// virtual int calculate(int _num_of_inputs,...);
// private:   
// };
// int And_gate::calculate(int _num_of_inputs,...)
// {
//     vector<int> nums;
//     va_list val;
//     va_start(val,_num_of_inputs);
//     for(int i=0;i<_num_of_inputs;i++)
//         nums.push_back(va_arg(val,int));
//     va_end(val);
//     input_ids = nums;
//     for(int i=0;i<nums.size();i++)
//         if(nums[i]==0)
//             return 0;
//     return 1;
// }

// class Or_gate : public Gate{
// public:
// Or_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
// virtual int calculate(int _num_of_inputs,...);
// private:   
// };
// int Or_gate::calculate(int _num_of_inputs,...)
// {
//     vector<int> nums;
//     va_list val;
//     va_start(val,_num_of_inputs);
//     for(int i=0;i<_num_of_inputs;i++)
//         nums.push_back(va_arg(val,int));
//     va_end(val);
//     input_ids = nums;
//     for(int i=0;i<nums.size();i++)
//         if(nums[i]==1)
//             return 1;
//     return 0;
// }

// class Not_gate : public Gate{
// public:
// Not_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
// virtual int calculate(int _num_of_inputs,...);
// private:   
// };
// int Not_gate::calculate(int _num_of_inputs,...)
// {
//     vector<int> nums;
//     va_list val;
//     va_start(val,_num_of_inputs);
//     for(int i=0;i<_num_of_inputs;i++)
//         nums.push_back(va_arg(val,int));
//     va_end(val);
//     input_ids = nums;
//     if(nums[0]==1)
//         return 0;
//     return 1;
// }

// class Xor_gate : public Gate{
// public:
// Xor_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
// virtual int calculate(int _num_of_inputs,...);
// private:   
// };
// int Xor_gate::calculate(int _num_of_inputs,...)
// {
//     vector<int> nums;
//     int count_1;
//     va_list val;
//     va_start(val,_num_of_inputs);
//     for(int i=0;i<_num_of_inputs;i++)
//         nums.push_back(va_arg(val,int));
//     va_end(val);
//     input_ids = nums;
//     for(int i=0;i<nums.size();i++)
//     {
//         if(nums[i]==1)
//             count_1++;
//     }
//     if(count_1%2==0)
//         return 0;
//     return 1;
// }

// class Nand_gate : public Gate{
// public:
// Nand_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
// virtual int calculate(int _num_of_inputs,...);
// private:   
// };
// int Nand_gate::calculate(int _num_of_inputs,...)
// {
//     vector<int> nums;
//     int count_1;
//     va_list val;
//     va_start(val,_num_of_inputs);
//     for(int i=0;i<_num_of_inputs;i++)
//         nums.push_back(va_arg(val,int));
//     va_end(val);
//     input_ids = nums;
//     for(int i=0;i<nums.size();i++)
//         if(nums[i]==0)
//             return 1;
//     return 0;
// }

// class Nor_gate : public Gate{
// public:
// Nor_gate(int _num_of_inputs,int _output_id): Gate(_num_of_inputs,_output_id){}
// virtual int calculate(int _num_of_inputs,...);
// private:   
// };
// int Nor_gate::calculate(int _num_of_inputs,...)
// {
//     vector<int> nums;
//     va_list val;
//     va_start(val,_num_of_inputs);
//     for(int i=0;i<_num_of_inputs;i++)
//         nums.push_back(va_arg(val,int));
//     va_end(val);
//     input_ids = nums;
//     for(int i=0;i<nums.size();i++)
//         if(nums[i]==1)
//             return 0;
//     return 1;
// }

// class wire
// {
// public:
//     wire(int input,int output)
//     {
//         input_id=input;
//         output_id=output;
//     }
//     int get_input_id()
//     {
//         return input_id;
//     }
//     int get_output_id()
//     {
//         return output_id;
//     }
// private:
//     int input_id;
//     int output_id;
// };

// class Circuit{
// public:
// void add_gate_to_circuit(GateType g_type,int num_of_inputs,int output_id,...);
// void connect(int inp,int oup);
// void print_gate_output(int oup);
// void put_value_on_gate_input(int gate_id, int value){};
// Gate* find_gate(int id)
// {
//     Gate* temp_gate;
//     for(int i=0;i<Gates.size();i++)
//     {
//         if (Gates[i]->get_output_id()==id)
//             temp_gate= Gates[i];
//     }
//     return temp_gate;
// }
// bool is_in_gates(int id);
// private:
// vector <Gate*> Gates;
// vector <wire*> wires;
// };

// bool Circuit::is_in_gates(int id)
// {
//     Gate* temp_gate;
//     for(int i=0;i<Gates.size();i++)
//     {
//         for(int j=0;j<temp_gate->get_input_ids().size();j++)
//         {
//             if (temp_gate->get_input_ids()[j]== Gates[i]->get_output_id())
//                 return true;
//         }
//     }
//     return false;
// }

// void Circuit::print_gate_output(int oup)
// {
   
//     Gate* temp_gate;
//     int x=Gates.size();
//     for(int i=0;i<Gates.size();i++)
//     {
//         if (Gates[i]->get_output_id()==oup)
//             temp_gate= Gates[i];
//     }
//     while(Gates.size()<oup)
//     {
//         int id = temp_gate->get_output_id();
//         Gate* new_g;
//         break;
//     }
    
// }

// void Circuit::connect(int inp,int oup)
// {
//     wire* new_wire =  new wire(inp,oup);
//     wires.push_back(new_wire);
// }
// void Circuit::add_gate_to_circuit(GateType g_type,int num_of_inputs,int output_id,...)
// {
//         if(g_type==And)
//         {
//             Gate* new_gate= new And_gate(num_of_inputs,output_id);
//             Gates.push_back(new_gate);
//         }
//          if(g_type==Or)
//         {
//             Gate* new_gate= new Or_gate(num_of_inputs,output_id);
//             Gates.push_back(new_gate);
//         } 
//         if(g_type==Not)
//         {
//             Gate* new_gate= new Not_gate(num_of_inputs,output_id);
//             Gates.push_back(new_gate);
//         } 
//         if(g_type==Xor)
//         {
//             Gate* new_gate= new Xor_gate(num_of_inputs,output_id);
//             Gates.push_back(new_gate);
//         } 
//         if(g_type==Nand)
//         {
//             Gate* new_gate= new Nand_gate(num_of_inputs,output_id);
//             Gates.push_back(new_gate);
//         } 
//         if(g_type==Nor)
//         {
//             Gate* new_gate= new Nor_gate(num_of_inputs,output_id);
//             Gates.push_back(new_gate);
//         }
// }


int main()
{
    Circuit circuit;
    circuit.add_gate_to_circuit(Nand, 2, 2, 1, 0);
    circuit.add_gate_to_circuit(Not, 1, 4, 3);
    circuit.add_gate_to_circuit(Xor, 2, 7, 6, 5);
    circuit.connect(4,6);
    circuit.connect(2,5);
    circuit.put_value_on_gate_input(0, 0);
    circuit.put_value_on_gate_input(1, 1);
    circuit.put_value_on_gate_input(3,1);
    circuit.print_gate_output(7); //result should be 1
    circuit.print_gate_output(4);
    circuit.print_gate_output(2);
    return 0;
}
