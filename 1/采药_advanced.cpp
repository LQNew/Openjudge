//通过分析可以发现，0-1背包问题的状态转移之间只与上一次的状态有关，所以我们可以将前j中物品这种修饰性的表述移除，于是二维数组转换为一维数组操作，降低了空间复杂度
#include<iostream>
using namespace std;
int T,M;
int time_1[101];
int value[101];
int dp[1001];//dp[i][j]表示装前j种物品，时间不超过i的最大价值
int main(){
    cin>>T>>M;
    for(int i=1;i<=M;i++) cin>>time_1[i]>>value[i];
    for(int i=0;i<=T;i++) dp[i]=0; //初始化，装前0件物品，价值定为0，作为递归的初始条件
    for(int j=1;j<=M;j++){
        for(int i=T;i>=time_1[j];i--) dp[i]=max(dp[i],dp[i-time_1[j]]+value[j]);
        for(int i=time_1[j]-1;i>=0;i--) dp[i]=dp[i];
    }
    cout<<dp[T]<<endl;
    return 0;
}
