//典型的完全背包问题，在0-1背包问题上，对于每个物体的数目不加限制，可以为任意个。
//由于每个钱币的数量都可以有任意多，所以该问题为完全背包问题。但是在该例中，完全背包有两处变化，首先，要求的不再是最大值，而变为了最小值，
//这就要求我们在状态转移时，在 dp[i]和 dp[i-weight[j]]+value[j] 中选择较小的转移值；其次，该问题要求钱币和空储蓄罐的重量恰好达到总重量，即在背包问题中表现为背包恰好装满，
//为了解决背包必须恰巧装满的处理，我们一开始背包每个容量出都初始化为一个无穷大数，只有查询至该容量即改容量对应有组合时才会更改数值
//本道题引入了最大数，我觉得int型可能最大值为 0X7FFFFFFF!
#include<iostream>
using namespace std;
const int INF=0x7fffffff;
int T;
int E,F;
int total_weight;
int N;
int value[501];
int weight[501];
int dp[10001];//dp[i][j]表示装前j种硬币，重量为i时的最小价值
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>E>>F>>N;
        for(int i=1;i<=N;i++) cin>>value[i]>>weight[i];
        total_weight=F-E;
        for(int i=1;i<=total_weight;i++) dp[i]=INF;
        dp[0]=0;
        for(int j=1;j<=N;j++){
            for(int i=weight[j];i<=total_weight;i++){
                if(dp[i-weight[j]]!=INF) dp[i]=min(dp[i],dp[i-weight[j]]+value[j]);
            }
        }
        if(dp[total_weight]==INF) cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<dp[total_weight]<<'.'<<endl;
    }
    return 0;
}
