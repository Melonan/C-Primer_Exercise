#ifndef EX7_32_H
#define EX7_32_H 

#include<vector>
#include<string>



class Screen; // Screen前向声明 , 因为在Window_mgr中要用到Screen作为参数


class Window_mgr
{
private:
    std::vector<Screen> screens; 
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    Window_mgr(/* args */);
    ~Window_mgr();
};

class Screen
{
    // 声明clear为友元  这样clear函数就能访问Screen对象中的private元素了
    friend void Window_mgr::clear(ScreenIndex);
    
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

        pos size() const ;



};

Screen::Screen(pos ht, pos wt, char c):height(ht),width(wt),contents(ht*wt,c){}

Screen::~Screen(){}

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

//  7.33 类作用域
// 第二个Screen:: 作用域为参数列表 + 函数体, 不包括返回类型
// so 添加第一个Screen:: 作用域是pos
Screen::pos Screen::size() const{
    return height * width;
}


Window_mgr::Window_mgr(/* args */){}

Window_mgr::~Window_mgr(){}

void Window_mgr::clear(ScreenIndex i)
{
    if(i>=screens.size()) return ;
    // 检查是否越界
    Screen &now = screens[i];
    now.contents = std::string(now.height * now.width, ' ');

}




#endif