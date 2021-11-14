#ifndef SCREEN_H
#define SCREEN_H

#include<string>

class Screen
{
public:
    using pos = std::string::size_type;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;


public:

    Screen() = default;
    
    Screen(pos ht, pos wt, char c);
    ~Screen();

    // 隐式内联
    char get() const{
        return contents[cursor];
    }
    // 显式内联
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);

};

Screen::Screen(pos ht, pos wt, char c):height(ht),width(wt),contents(ht*wt,c)
{
}

Screen::~Screen()
{
}

char Screen::get(pos r, pos c)const{
    // 给定行号列号
    pos row = r*width;
    return contents[row + c];
}

Screen &Screen::move(pos r , pos c)
{
    cursor = r * width + c;
    return *this;
}
#endif
