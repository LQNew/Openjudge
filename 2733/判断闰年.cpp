/*
    描述
        判断某年是否是闰年。
    输入
        输入只有一行，包含一个整数a(0 < a < 3000)
    输出
        一行，如果公元a年是闰年输出Y，否则输出N
*/
//水题
#include<iostream>
using namespace std;
int a;
int main()
{
    cin>>a;
    if(a%4==0)
    {
        if(a%100==0&&a%400!=0)
            cout<<"N"<<endl;
        else
            cout<<"Y"<<endl;
    }
    else
        cout<<"N"<<endl;
    return 0;
}
