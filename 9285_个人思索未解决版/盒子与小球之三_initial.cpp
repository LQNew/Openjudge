//试图按照盒子与小球之四去理解本问题，码了最基本模式的代码，但不知道为什么，逻辑可能出问题导致无法跑通样例...
//???始终没有跑通不清楚为什么....
#include<iostream>
using namespace std;
int dp[5001][5001];
const int mod=1000007;
int N,M,K;
int main(){
    while(cin>>N>>M>>K){
        dp[0][0]=1;
        for(int i=1;i<=N;i++){
            dp[i][0]=0;
            if(i<=K) dp[i][1]=1;
            else dp[i][1]=0;
            dp[0][i]=1;
        }
        for(int i=2;i<=N;i++){ // i个球
            for(int j=2;j<=M;j++){ //j个盒子
                dp[i][j]=0;
                for(int t=0;t<=min(i,K);t++) dp[i][j]=(dp[i][j]+dp[i-t][j-1])%mod;
                //cout<<dp[i][j]<<endl;
            }
        }
        cout<<dp[N][M]<<endl;
    }
    return 0;
}
