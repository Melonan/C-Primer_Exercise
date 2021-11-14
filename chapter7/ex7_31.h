#ifndef EX7_31_H
#define EX7_31_h

// 得先声明一下Y类, 不然无法使用Y的引用或指针
class Y;
class X
{
private:
    Y* ptr2Y;
public:
    X(/* args */){};
    ~X(){};
};

class Y
{
private:
    X objX;
public:
    Y(/* args */){};
    ~Y(){};
};







#endif