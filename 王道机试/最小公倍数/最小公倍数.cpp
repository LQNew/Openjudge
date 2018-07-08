//最小公倍数的思想就是，求出a和b的最大公约数，将a和b相乘后，除以这个最大公约数就是a和b的最小公倍数~
#include<iostream>
using namespace std;
int a,b;
int main()
{
    while(cin>>a>>b)
    {
        int t;
        int a1=a;
        int b1=b;
        while(b!=0)
        {
            t=a;
            a=b;
            b=t%b;
        }
        cout<<(a1*b1)/a<<endl;
    }
    return 0;
}
