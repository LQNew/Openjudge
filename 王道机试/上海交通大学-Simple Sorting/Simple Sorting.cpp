//去除重复的个数输出，简单题型，排序后再遍历一遍，复杂度为 n*log(n)+n，小于百万级
//此处比较恶心的地方是最后一个输出不能有空格，很恶心的地方！！为此专门开了一个数组去存储以保证跑通但是没有意义
#include<iostream>
using namespace std;
int N;
int num[1000];
int store[1000];
int before,now;

int compare(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>num[i];
        }
        qsort(num,N,sizeof(num[0]),compare);
        int cnt=0;
        before=num[0];
        store[cnt++]=before;
        for(int i=1;i<N;i++)
        {
            now=num[i];
            if(before==now)
                continue;
            else
            {
                store[cnt++]=now;
                before=now;
            }
        }
        for(int i=0;i<cnt-1;i++)
            cout<<store[i]<<" ";
        cout<<store[cnt-1]<<endl;
    }
    return 0;
}
