#ifndef EX7_24_H
#define EX7_24_H

#include<string>

class Screen
{
public:
    using pos = std::string::size_type;
private:
    pos height = 0 ;
    pos width = 0;
    std::string contents;
public:
    Screen() = default;
    Screen(pos ht, pos wd):height(ht),width(wd),contents(ht*wd,' '){}
    Screen(pos ht, pos wd , char c): height(ht), width(wd), contents(ht*wd,c){}    
    ~Screen();
};

Screen::Screen()
{
}

Screen::~Screen()
{
}




#endif