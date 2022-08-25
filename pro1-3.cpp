#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum OperatorType { DUMMY_ROOT,Add, Multiply, Not, Median};
class Parent_node_not_found {};
class Invalid_parent{};
class Invalid_tree_structure{};
class Node
{
public:
Node(int keep_id, int keep_parent_id) : id(keep_id), parent_id(keep_parent_id) {}
    int get_id(){ return id;}
    int get_parent_id(){return parent_id;}
    string get_node_type(){return node_type;}
virtual int calculate(int x, int y)=0;
protected:
int id, parent_id;
string node_type;

};

class Operand : public Node 
{
public:
Operand(int keep_id, int keep_parent_id, int keep_value ) :Node(keep_id, keep_parent_id), value(keep_value){node_type = "operand";}
int get_value(){return value;}
int calculate(int x, int y){return 0;}
private:
int value;

};

class Operator : public Node 
{
public:
    Operator(int keep_id, int keep_parent_id, OperatorType  keep_type ) :Node(keep_id, keep_parent_id), type(keep_type){}             
    OperatorType get_type(){return type;}
    virtual int calculate(int x, int y){return 0;}
    virtual int calculate_med(vector<int> nums){return 0;}
private:
    OperatorType type;
}; 

class add_operator : public Operator
{
public:
add_operator(int keep_id, int keep_parent_id, OperatorType  keep_type = Add):Operator(keep_id, keep_parent_id,keep_type){node_type = "add";}
int calculate(int x, int y);
private:
int x;
int y;
};

int add_operator :: calculate(int x, int y)
{
    int sum;
    sum=x+y;
    return sum;
} 

class multiply_opertor : public Operator
{
public:
multiply_opertor(int keep_id, int keep_parent_id, OperatorType  keep_type=Multiply):Operator(keep_id, keep_parent_id,keep_type){node_type = "multiply";}
int calculate(int x, int y);
private:
int x;
int y;
};

int  multiply_opertor :: calculate(int x, int y)
{
    int multi;
    multi=x*y;
    return multi;
} 

class not_operator : public Operator
{
public:
not_operator(int keep_id, int keep_parent_id, OperatorType  keep_type=Not):Operator(keep_id, keep_parent_id,keep_type){node_type="not";}
int calculate(int x, int y);
private:
int x;
int y;
};

int not_operator :: calculate(int x, int y)
{
    int not_num;
    not_num=x*(-1);
    return not_num;
}

class med_operator : public Operator
{
public:
med_operator(int keep_id, int keep_parent_id, OperatorType  keep_type=Median):Operator(keep_id, keep_parent_id,keep_type){node_type="median";}
int calculate_med(vector<int>nums);
private:
};

int med_operator:: calculate_med(vector<int>nums)
{
    if(nums.size()%2!=0)
        return nums[nums.size()/2];

    else
        return (nums[(nums.size()/2)]+nums[(nums.size()/2)-1])/2;
}

class Tree{
public:
Tree()
{
    Operand* new_node = new Operand(0,DUMMY_ROOT,0);
    Operands.push_back(new_node);
}
  void add_operand_node(const size_t id, const size_t parent_id, const int value);
  void add_operator_node(const size_t id, const size_t parent_id, const OperatorType type);
  int evaluate_tree();
  int is_in_nodes_2_roots();
private:
vector<Node*>Nodes;
vector<Operator*>Operators;
vector<Operand*>Operands;
};

int Tree::evaluate_tree()
{
    int final_ans;
    for(int i=Operators.size()-1;i>=0;i--)
    {
        if(Operators[i]->get_node_type() == "add" || Operators[i]->get_node_type()=="multiply")
        {    
            vector<int> nums;
            try{
                for(int j=0;j<Operands.size();j++)
                {
                    if(Operands[j]->get_parent_id() == Operators[i]->get_id())
                    {
                        nums.push_back(Operands[j]->get_value());
                    }
                }
                if(nums.size()!=2)
                    throw Invalid_tree_structure();
            }
            catch(Invalid_tree_structure x){
        cout<<"Invalid tree structure"<<endl;
    }
            int answer = Operators[i]->calculate(nums[0],nums[1]);
            Operand* new_node = new Operand(Operators[i]->get_id(),Operators[i]->get_parent_id(),answer);
            Operands.push_back(new_node);
        }

        if(Operators[i]->get_node_type() == "not")
        {
            int num;
            for(int j=0;j<Operands.size();i++)
            {
                if(Operands[j]->get_parent_id() == Operators[i]->get_id())
                    num = Operands[j]->get_value();
            }
            int answer = Operators[i]->calculate(num,0);
            Operand* new_node = new Operand(Operators[i]->get_id(),Operators[i]->get_parent_id(),answer);
            Operands.push_back(new_node);
        }
        if(Operators[i]->get_node_type() == "median")
        {
            vector<int> nums;
            for(int j=0;j<Operands.size();i++)
            {
                if(Operands[j]->get_parent_id() == Operators[i]->get_id())
                    nums.push_back( Operands[j]->get_value());
            }
            int answer = Operators[i]->calculate_med(nums);
            Operand* new_node = new Operand(Operators[i]->get_id(),Operators[i]->get_parent_id(),answer);
            Operands.push_back(new_node);
        }
    }
    for(int i=0;i<Operands.size();i++)
    {
        if (Operands[i]->get_parent_id()== DUMMY_ROOT)
            final_ans = Operands[i]->get_value();
    }
    return final_ans;
}

void Tree::add_operand_node(const size_t id, const size_t parent_id, const int value)
{
    int seen=0;
    try{
    for(int i=0;i<Operators.size();i++)
        if(Operators[i]->get_id()==parent_id)
            seen=1;
    for(int i=0;i<Operands.size();i++)
        if(Operands[i]->get_id()==parent_id)
            seen=1;
    if(seen==0)
        throw Parent_node_not_found();
    }
    catch(Parent_node_not_found x){
        cout<<"Parent node not found"<<endl;
    }
    
    int seen2=0;
    try{
    for(int i=0;i<Operators.size();i++)
        if(Operators[i]->get_id()==parent_id)
            seen2=1;
    if(seen2==0)
        throw Invalid_parent();
    }
    catch(Invalid_parent x){
        cout<<"Invalid parent"<<endl;
    }
    Operand* new_operand = new Operand(id, parent_id, value);
    Operands.push_back(new_operand);

};

int Tree::is_in_nodes_2_roots()
{
    int seen=0;
    for(int i=0;i<Operators.size();i++)
        if(Operators[i]->get_parent_id()==DUMMY_ROOT)
            seen++;
    for(int i=0;i<Operands.size();i++)
        if(Operands[i]->get_parent_id()==DUMMY_ROOT)
            seen++;
    return seen;
}

void Tree::add_operator_node(const size_t id, const size_t parent_id, const OperatorType type)
{
  
   int seen=0;
    try{
    for(int i=0;i<Operators.size();i++)
        if(Operators[i]->get_id()==parent_id)
            seen=1;
    for(int i=0;i<Operands.size();i++)
        if(Operands[i]->get_id()==parent_id)
            seen=1;
    if(seen==0)
        throw Parent_node_not_found();
    }
    catch(Parent_node_not_found x){
        cout<<"Parent node not found"<<endl;
    }

    try {
        if(parent_id==0 && is_in_nodes_2_roots()!=1)
        {
            throw Invalid_parent();  
        }
    }
    catch(Invalid_parent x){
        cout<<"Invalid parent"<<endl;
    }


    int seen2=0;
    try{
    for(int i=0;i<Operators.size();i++)
        if(Operators[i]->get_id()==parent_id)
            seen2=1;
        if(parent_id==0)
            seen2=1;
    if(seen2==0)
        throw Invalid_parent();
    }
    catch(Invalid_parent x){
        cout<<"Invalid parent"<<endl;
    }

    if(type == Add)
    {
        Operator* new_operator1 = new add_operator(id,parent_id,type);
        Operators.push_back(new_operator1);
    }
    else if(type == Multiply)
    {
        Operator* new_operator2 = new multiply_opertor(id,parent_id,type);
        Operators.push_back(new_operator2);
    }
    else if(type == Not)
    {
        Operator* new_operator3 = new not_operator(id,parent_id,type);
        Operators.push_back(new_operator3);
    }
    else if(type == Median)
    {
        Operator* new_operator4 = new med_operator(id,parent_id,type);
        Operators.push_back(new_operator4);
    }
}
