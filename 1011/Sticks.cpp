/*
    George took sticks of the same length and cut them randomly until all parts became at most 50 units long.
    Now he wants to return sticks to the original state, but he forgot how many sticks he had originally and how long they were originally.
    Please help him and design a program which computes the smallest possible original length of those sticks.
    All lengths expressed in units are integers greater than zero.
*/
//已知一堆切分后的木棍各个长度，请将它们拼成原有的统一的长度，要求统一的长度是可以拼出的长度中最短的
//本道题难度较大，主要用到了深搜的递归，但是我对于深搜理解得不是很好，此题的解释就待定..em...
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N,L;
int total_length;
int sticks[65];
int used[65];

int compare(const void*a,const void*b)
{
    return *(int*)b - *(int*)a ;
}

bool Dfs(int num,int remain_length,int length) //length表示要拼的目标木棍的长度
{
    if(num==0&&remain_length==0)
        return true;
    if(remain_length==0)
        remain_length=length;
    for(int i=0;i<N;i++)
    {
        if(!used[i]&& sticks[i]<=remain_length)
        {
            used[i]=1;
            if(Dfs(num-1,remain_length-sticks[i],length))
                return true;
            else
                used[i]=0;
        }
    }
    return false;
}

int main()
{
    while(1)
    {
        cin>>N;
        if(N==0)
            break;
        total_length=0;
        for(int i=0;i<N;i++)
        {
            cin>>sticks[i];
            total_length+=sticks[i];
        }
        qsort(sticks,N,sizeof(sticks[0]),compare); //将输入的木棍从大到小排序
        /*
            for(int i=0;i<N;i++)
                cout<<sticks[i]<<" ";
            cout<<endl;
        */
        for(L=sticks[0];L<=total_length/2;L++)
        {
            if(total_length%L) //最短木棍长度一定是总长度的因子！！取余应该为0~
                continue;
            memset(used,0,sizeof(used[0])*N);
            if(Dfs(N,L,L))
            {
                cout<<L<<endl;
                break;
            }
        }
        if(L>total_length/2) cout<<total_length<<endl;
    }
    return 0;
}
