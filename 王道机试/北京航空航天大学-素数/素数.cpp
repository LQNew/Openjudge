//本道题难度不大，时间复杂度为O(n)+O(n/10)*O(sqrt(n)),由于n<10000，所以量级也就是十万级别，小于百万级别所以没事~
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int prime[10000];
bool judge(int m)
{
    for(int i=2;i<=sqrt(m);i++)
        if(m%i==0) return false;
    return true;
}
int main()
{
    while(cin>>n)
    {
        memset(prime,0,sizeof(prime[0]));
        int j=0;
        for(int i=2;i<n;i++)
        {
            if(i%10!=1) continue;
            else
                if(judge(i))  prime[j++]=i;
        }
        if(j==0) cout<<-1<<endl;
        else
        {
            for(int i=0;i<j-1;i++)
                cout<<prime[i]<<" ";
            cout<<prime[j-1]<<endl;
        }
    }
    return 0;
}
