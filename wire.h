#ifndef WIRE_H
#define WIRE_H
class wire
{
public:
    wire(int input,int output);
    int get_input_id(){return input_id;}
    int get_output_id(){return output_id;}
private:
    int input_id;
    int output_id;
};
#endif