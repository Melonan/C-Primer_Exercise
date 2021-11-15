#ifndef EX7_32_H 
#define EX7_32_H


void f();
struct X
{
    friend void f()
    {

    }
    X()
    {f();}
    void g();
    void h();
};

void X::g()
{
    return f();
}



void X::h()
{
    return f();
}




#endif