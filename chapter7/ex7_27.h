#ifndef SCREEN_H
#define SCREEN_H

#include<string>
#include<iostream>
class Screen
{
public:
    using pos = std::string::size_type;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    //  mutable 变量: 可变数据成员 , 即使在Const 成员函数内都可以修改 挺离谱的
    mutable size_t access_ctr = 0;

    void do_display(std::ostream &os) const
    {
        os<<contents;
    }

public:

    Screen() = default;
    
    Screen(pos ht, pos wt, char c);
    Screen(pos ht, pos wd ): height(ht), width(wd) , contents(ht*wd, ' '){}
    ~Screen();

    //get  
    // 隐式内联
    char get() const
    {
        some_member();
        return contents[cursor];
    }
    // 显式内联
    inline char get(pos ht, pos wd) const;
    

    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos , pos ,char);


    void some_member()const;

    // display
    // 返回一个非常量引用
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }

    // 返回一个常量引用
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

};

Screen::Screen(pos ht, pos wt, char c):height(ht),width(wt),contents(ht*wt,c){}

Screen::~Screen(){}

// 两个内联的set函数
inline
Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col , char ch)
{
    contents[r*width+col] = ch;
    return *this;
}

// 调用mutable变量的函数 , 统计get函数调用的次数
// 虽然没啥用, 这里主要是想体现一下 在const 成员函数中  mutable变量都可以修改
void Screen::some_member()const
{
    ++access_ctr;
    std::cout<<"Access_Ctr: "<<access_ctr<<std::endl;
}

char Screen::get(pos r, pos c)const{
    // 给定行号列号
    pos row = r*width;
    some_member();
    return contents[row + c];
}

//  move 函数
Screen &Screen::move(pos r , pos c)
{
    cursor = r * width + c;
    some_member();
    return *this;
}

#endif
