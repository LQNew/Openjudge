//最基础的动归方程，但是超时..
//思路很简单，就是dp[i][j]来表示前i个盒子中有j个球，那么这种可能的数目其实是对于前i-1个盒子中有 j-k~j个球的概率，当然有个附加条件，就是 此处的求和
// 因为可能本身j都小于k，所以要有个额外的小处理
#include<iostream>
using namespace std;
int dp[5001][5001];
int N,M,K;
int mod=1000007;
int main(){
    while(cin>>N>>M>>K){
        dp[0][0]=1;
        for(int j=1;j<=N;j++) dp[0][j]=0;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                dp[i][j]=0;
                for(int p=0;p<=min(j,K);p++){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-p])%mod;
                }
            }
        }
        cout<<dp[M][N]<<endl;
    }
    return 0;
}
