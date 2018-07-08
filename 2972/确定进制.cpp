/*
输入：
一行，包含三个整数p、q、r，相邻两个整数之间用单个空格隔开。 p、q、r的所有位都是数字，并且1 <= p、q、r <= 1,000,000。
输出：
一个整数：即使得p * q = r成立的最小的B。如果没有合适的B，则输出 0。
*/
//分析：此题较简单，只需对于整数剥离出每一位的数字，然后计算不同进制下的值，需要注意的是有时各个位的数字可能大于进制数，此时是不合理地，需要处理
//分析幂次时可以发现可能最大进制下的数值是超出int型表示的范围，所以应采纳更大的数制
#include<iostream>
using namespace std;
int factor_p[8],factor_q[8],factor_r[8]; //用于存储各个位上的数字
int cnt_p,cnt_q,cnt_r;

void Divide(int p,int q,int r) //除十取余，逆序输出，此便是剥离各位的数字
{
    int i=0,j=0,k=0; //关于多个数值的出始化，犯了一个极其幼稚的错误，int i,j,k=0; 这种方式知识初始化了k,i 以及 j 并没有初始化！这种低级错误记住切勿再犯！
    while(p>=10)
    {
        factor_p[i++]=p%10;
        p=p/10;
    }
    factor_p[i]=p;
    cnt_p=i;

    while(q>=10)
    {
        factor_q[j++]=q%10;
        q=q/10;
    }
    factor_q[j]=q;
    cnt_q=j;

    while(r>=10)
    {
        factor_r[k++]=r%10;
        r=r/10;
    }
    factor_r[k]=r;
    cnt_r=k;
}

long Power(int a,int b) //求幂次的函数
{
    long res = 1;
    while (b--) res *= a;
    return res;
}

bool Judge(int B) //计算不同幂次下的各数数值，并且判别 p*q是否等于r
{
    long num_p=0,num_q=0,num_r=0;
    for(int i=0;i<=cnt_p;i++)
    {
        if(factor_p[i]<B)
        {
            num_p+=factor_p[i]*Power(B,i);
        }
        else return false;
    }

    for(int i=0;i<=cnt_q;i++)
    {
        if(factor_q[i]<B)
        {
            num_q+=factor_q[i]*Power(B,i);
        }
        else return false;
    }

    for(int i=0;i<=cnt_r;i++)
    {
        if(factor_r[i]<B)
            num_r+=factor_r[i]*Power(B,i);
        else return false;
    }
    if(num_p*num_q==num_r) return true;
    else return false;

}

int Get_min() //若在2-16间获得了合适的进制满足条件，那么输出进制值，否则返回0
{
    for(int i=2;i<=16;i++)
    {
        if(Judge(i)) return i;
    }
    return 0;
}

int main()
{
    int p,q,r;
    while(cin>>p>>q>>r)
    {
        Divide(p,q,r);
        cout<<Get_min()<<endl;
    }
    return 0;
}
