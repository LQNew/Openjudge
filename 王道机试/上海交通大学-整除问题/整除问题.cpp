//因为数据数目不大，所以复杂度初步估计在O(n)-O(n^2)范围,小于百万级别，可以达到要求~
#include<iostream>
#include<cstring>
using namespace std;
int n,a;
int prime[1000];
bool mark[1001];
struct Node
{
    int value;
    int times;
};
Node num1[1000];
Node num2[1000];

int initial() //预处理,获取小于1000的所有素因子
{
    memset(mark,0,sizeof(mark[0]));
    memset(prime,0,sizeof(prime[0]));//数组的初始化！
    int cnt=0;
    for(int i=2;i<=1000;i++)
    {
        if(mark[i]==true) continue;
        prime[cnt++]=i;
        mark[i]=true;
        if(i>=100) continue;
        for(int k=i*i;k<=1000;k+=i)
        {
            mark[k]=true;
        }
    }
    return cnt;
}

int main()
{
    int cnt=initial();
    while(cin>>n>>a)
    {
        int sum;
        int flag=0;
        int flag1=0;
        for(int i=0;i<cnt;i++)
        {
            if(prime[i]>a) break;
            else
            {
                sum=0;
                while((a%prime[i]==0)&&a!=1)
                {
                    a=a/prime[i];
                    sum++;
                }
                if(sum!=0)
                {
                    num1[flag].times=sum;
                    num1[flag].value=prime[i];
                    flag++;
                }
            }
            if(a==1)
                break;
        }
        /*for(int i=0;i<flag;i++)
            cout<<num1[i].value<<" "<<num1[i].times<<endl;
        cout<<endl;*/
        for(int i=0;i<cnt;i++)
        {
            if(prime[i]>n) break;
            else
            {
                int N=n;
                sum=0;
                while(N!=0)
                {
                    num2[flag1].value=prime[i];
                    N=N/prime[i];
                    sum+=N;
                }
                num2[flag1].times=sum;
                flag1++;
            }
        }
        /*for(int i=0;i<flag1;i++)
            cout<<num2[i].value<<" "<<num2[i].times<<endl;
        cout<<endl;*/
        int min1;
        bool flagxx=false;
        for(int i=0;i<flag;i++)
        {
            for(int j=0;j<flag1;j++)
            {
                if(num2[j].value>num1[i].value) break;
                else if(num2[j].value==num1[i].value)
                {
                    if(!flagxx)
                    {
                        min1=num2[j].times/num1[i].times;
                        flagxx=true;
                    }
                    else
                    {
                        if(min1>num2[j].times/num1[i].times)
                            min1=num2[j].times/num1[i].times;
                    }
                }
            }
        }
        cout<<min1<<endl;
    }
}
