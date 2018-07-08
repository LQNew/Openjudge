/*
    写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。
*/
//分析：一开始认为是大整数乘法后来发现本道题就是道简单的题目，并没有涉及大数运算...那么就算是水题，当然本道题也可以出的很困难！！
//在自己心中默默分析了一下，如果考虑大数运算的话，需要每次计算幂次也应用到大整数乘法，关于幂次的运算可以采用快速幂算法，如王道中的A^B题~
#include<iostream>
#include<cstring>
using namespace std;
char num_sixteen[500];
long long num_ten;
int flag;
void transform_1() //转换进制函数
{
    int num;
    long b=1;
    int len=strlen(num_sixteen);
    for(int i=len-1;i>1;i--)
    {
        if(num_sixteen[i]>='0'&&num_sixteen[i]<='9')
            num=num_sixteen[i]-'0';
        else
            num=num_sixteen[i]-'A'+10;
        num_ten+=num*b;
        b*=16;
    }
}
int main()
{
    while(cin>>num_sixteen)
    {
        transform_1();
        cout<<num_ten<<endl;
        num_ten=0;
    }
    return 0;
}
