//分析数学公式，转换为因子式： (b-a)*(c-a)=a^2-1 -->b+c=m+n+2*a，其中m、n为因子
#include<iostream>
using namespace std;
long long a; //关键点在于 普通的整形无法存储计算值，于是采用long long 型存储，注意一开始本道题解时a采用了int 型，导致进制之间的混乱（可能是这个原因...）
             //导致了Wa一次
int main()
{
    cin>>a;
    long long q,i,sum,min_1;
    q=a*a+1;
    min_1=9999999999;
    for(i=1;i<a+1;i++) //遍历找到所有因子
    {
        if(q%i)
            continue;
        sum=q/i+i+2*a;
        if(sum<min_1)
            min_1=sum;
    }
    cout<<min_1<<endl;
    return 0;
}
