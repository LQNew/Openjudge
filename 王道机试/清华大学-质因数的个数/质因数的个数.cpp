//注：int型范围一般为 -21亿到21亿左右
//本道题为10亿，在范围之内
//分解素因数，POJ上也有此类题型，难度不大，解法与本道题解法思路不同，那是直接遍历去求
//本道题多了个预处理，时间复杂度为O(n)+100000*类似于哈希的一个复杂度，竟然复杂度小于百万级别，可能是因为那块的时间复杂度跳跃性太大吧orz...
//其实POJ上的常规解题，就是直接遍历，复杂度为O(sqrt(n))*一个常数项，时间复杂度更低...
#include<iostream>
#include<cstring>
using namespace std;
int N;
bool mark[100001];
int prime[100000];
int initial() //预处理
{
    memset(mark,0,sizeof(mark[0]));
    memset(prime,0,sizeof(prime[0]));//数组的初始化！
    int cnt=0;
    for(int i=2;i<=100000;i++)
    {
        if(mark[i]==true) continue;
        prime[cnt++]=i;
        mark[i]=true;
        if(i>=1000) continue;
        for(int k=i*i;k<=100000;k+=i)
        {
            mark[k]=true;
        }
    }
    return cnt;
}
int main()
{
    int cnt=initial();
    while(cin>>N)
    {
        int sum=0;
        for(int i=0;i<cnt;i++)
        {
            if(prime[i]>N) break;
            else
            {
                while((N%prime[i]==0)&&N!=1)
                {
                    N=N/prime[i];
                    sum++;
                }
            }
            if(N==1)
                break;
        }
        if(N!=1)
        {
            prime[cnt++]=N;
            cout<<sum+1<<endl;
        }
        else
            cout<<sum<<endl;
    }
    return 0;
}
