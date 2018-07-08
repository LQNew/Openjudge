//典型的0-1背包问题，题目主要是要理解动归思路~难度不大，模板题型！
#include<iostream>
#include<cstring>
using namespace std;
int N,M;
int weight[4000];
int rating[4000];
int dp[12880]; //dp[j]表示前j重量内目前的最大金额
int main(){
    while(cin>>N>>M){
        for(int i=1;i<=N;i++){
            cin>>weight[i]>>rating[i];
        }
        dp[0]=0;
        memset(dp,0,sizeof(dp[0]*(M+1)));
        for(int i=1;i<=N;i++){
            for(int j=M;j>=weight[i];j--){
                if(dp[j]<dp[j-weight[i]]+rating[i]) dp[j]=dp[j-weight[i]]+rating[i];
            }
        }
        cout<<dp[M]<<endl;
    }
    return 0;
}
