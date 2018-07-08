//dp问题，但是思路没有典型的模板0-1背包问题好想，这道题还是蛮有意思的01背包变种题，要多加回顾，多多理解，保证之后能快速编写出代码
#include<iostream>
#include<cstring>
using namespace std;
int N,K;
int a[101];
int dp[101][100];
int main(){
    cin>>N>>K;
    for(int i=1;i<=N;i++) cin>>a[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;i++){
        for(int j=0;j<K;j++) dp[i][j]=dp[i-1][j];
        for(int j=0;j<K;j++){
            if((dp[i-1][j]==0)&&(j!=0)) continue;
            dp[i][(j+a[i])%K]=max(dp[i][(j+a[i])%K],dp[i-1][j]+a[i]);

        }
    }
    cout<<dp[N][0]<<endl;
    return 0;
}
