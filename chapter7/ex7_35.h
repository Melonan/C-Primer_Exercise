#ifndef EX7_35_H
#define EX7_35_H

#include<string>

typedef std::string Type ; 

Type initVal();

class Exercise
{
    // typedef double Type;
private:
    typedef double Type;
    int val;
public:
    Exercise();
    ~Exercise();
    
    
    Type setVal(Type);
    Type initVal();
    
};

Exercise::Type Exercise::setVal(Type parm)
{
    val = parm+initVal();
    return val;
}
Exercise::Exercise()
{
}

Exercise::~Exercise()
{
}







#endif