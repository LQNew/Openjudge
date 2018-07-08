//高精度运算
//进制转换问题，本道题对于数字位数没有那么高，所以可以用long long型存储
#include<iostream>
#include<cstring>
using namespace std;
int m;
long long A,B,sum,sum1;
int final[40];

int main()
{
    while(cin>>m)
    {
        if(m==0)
            break;
        cin>>A>>B;
        sum=A+B;
        sum1=sum;
        int flag=0;
        memset(final,0,sizeof(final[0]));
        if(sum==0) //留意此处！
        {
            cout<<0<<endl;
            continue;
        }
        while(sum!=0)
        {
            sum=sum/m;
            final[flag++]=sum1%m;
            sum1=sum;
        }
        for(int i=flag;i--;i>=0)
            cout<<final[i];
        cout<<endl;
    }
    return 0;
}
