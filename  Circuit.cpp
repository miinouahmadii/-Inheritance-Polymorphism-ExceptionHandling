#include "Circuit.h"
#include <iostream>


bool Circuit::is_in_gates(int id)
{
    Gate* temp_gate;
    for(int i=0;i<Gates.size();i++)
    {
        for(int j=0;j<temp_gate->get_input_ids().size();j++)
        {
            if (temp_gate->get_input_ids()[j]== Gates[i]->get_output_id())
                return true;
        }
    }
    return false;
}

void Circuit::print_gate_output(int oup)
{
   
    Gate* temp_gate;
    int x=Gates.size();
    for(int i=0;i<Gates.size();i++)
    {
        if (Gates[i]->get_output_id()==oup)
            temp_gate= Gates[i];
    }
    while(Gates.size()<oup)
    {
        int id = temp_gate->get_output_id();
        Gate* new_g;
        break;
    }
    
}

void Circuit::connect(int inp,int oup)
{
    wire* new_wire =  new wire(inp,oup);
    wires.push_back(new_wire);
}

void Circuit::add_gate_to_circuit(GateType g_type,int num_of_inputs,int output_id,...)
{
        if(g_type==And)
        {
            Gate* new_gate= new And_gate(num_of_inputs,output_id);
            Gates.push_back(new_gate);
        }
         if(g_type==Or)
        {
            Gate* new_gate= new Or_gate(num_of_inputs,output_id);
            Gates.push_back(new_gate);
        } 
        if(g_type==Not)
        {
            Gate* new_gate= new Not_gate(num_of_inputs,output_id);
            Gates.push_back(new_gate);
        } 
        if(g_type==Xor)
        {
            Gate* new_gate= new Xor_gate(num_of_inputs,output_id);
            Gates.push_back(new_gate);
        } 
        if(g_type==Nand)
        {
            Gate* new_gate= new Nand_gate(num_of_inputs,output_id);
            Gates.push_back(new_gate);
        } 
        if(g_type==Nor)
        {
            Gate* new_gate= new Nor_gate(num_of_inputs,output_id);
            Gates.push_back(new_gate);
        }
}

Gate* Circuit::find_gate(int id)
{
    Gate* temp_gate;
    for(int i=0;i<Gates.size();i++)
    {
        if (Gates[i]->get_output_id()==id)
            temp_gate= Gates[i];
    }
    return temp_gate;
}
