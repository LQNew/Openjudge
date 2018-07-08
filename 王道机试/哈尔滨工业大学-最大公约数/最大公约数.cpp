//欧几里德算法！最大公约数的解法：a和b的最大公约数一定也是 b和a%b的最大公约数
//如果a和b，b为0，a为正整数，那么最大公约数为a，非常好的算法思路~
#include<iostream>
using namespace std;
int a,b;
int main()
{
    while(cin>>a>>b)
    {
        int t;
        while(b!=0)
        {
            t=a;
            a=b;
            b=t%b;
        }
        cout<<a<<endl;
    }
    return 0;
}
