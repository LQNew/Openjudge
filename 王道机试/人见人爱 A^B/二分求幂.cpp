//求四位数幂次的后三位，其实对于乘法运算，后三位都是后三位去乘得到的
//二分求幂的思想很棒，很有用处！要多多体会！！
#include<iostream>
using namespace std;
int decomposition[14];//存储P的分解值
int A,B;
int Decomposition() //将p分解为2的因子式
{
    int p_1=B;
    int i=0;
    while(p_1!=0)
    {
        if(p_1%2)
        {
            decomposition[i]=1;
            p_1=p_1/2;
        }
        else
        {
            p_1=p_1/2;
            decomposition[i]=0;
        }
        i++;
    }
    return i;
}
int main()
{
    while(cin>>A>>B)
    {
        if(A==0&&B==0)
            break;
        int cnt=Decomposition();
        int ans=A;
        int final=1;
        for(int i=0;i<cnt;i++)
        {
            if(decomposition[i]==1)
            {
                final*=ans;
                final%=1000;
            }
            ans=ans*ans;
            ans%=1000;
        }
        cout<<final<<endl;
    }
    return 0;
}
