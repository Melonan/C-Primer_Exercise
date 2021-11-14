#include "ex7_27.h"
#include<iostream>

using namespace std;

int main()
{
    // 初始化一个Screen对象
    Screen myScreen(5,5,'x');

    myScreen.move(4,0).set('#').display(cout);

    cout<<"\n\n";

    myScreen.display(cout);
    cout<<"\n";

}