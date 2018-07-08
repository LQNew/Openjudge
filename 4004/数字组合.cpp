/*
    有n个正整数，找出其中和为t(t也是正整数)的可能的组合方式。如：n=5,5个数分别为1,2,3,4,5，t=5；
    那么可能的组合有5=1+4和5=2+3和5=5三种组合方式。
*/
//典型的深搜问题，就是划分枚举子集合求出使得组合值为t的集合数目
#include<iostream>
using namespace std;
int n,t;
int sum;
int ans;
int a[20];
void dfs(int x){ //子集合划分的详细代码~
    if(sum==t){
        ans++; //bingo!集合数目+1
        return;
    }
    if(x>=n) return;
    sum+=a[x];
    dfs(x+1);
    sum-=a[x];
    dfs(x+1);
}
int main(){
    while(cin>>n>>t){
        for(int i=0;i<n;i++) cin>>a[i];
        sum=0;
        ans=0;
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
