//经典的0-1背包问题，本程序思维很清晰，一定要彻底理解！！该问题可抽象为：
//有一个容量为 V 的背包，和一些物品。这些物品分别有两个属性，体积 w 和价值 v，每种物品只有一个。要求用这个背包装下价值尽可能多的物品，求该最大价值，背包可以不被装满。
//每个物品都有两种可能的情况，即在背包中或者不存在（背包中有0个该物品或者1个），所以我们把这个问题称为 0-1 背包问题。
//用dp[i][j]标识 装前j种物品，时间不超过i的最大价值。
//若物品 i 被放入背包，设其体积为 w，价值为 v，则 dp[i][j] = dp[i-w][j-1] + v。
//即在总体积不超过 i-w 时前j-1件物品可组成的最大价值的基础上再加上j物品的价值 v；若物品不加入背包，则 dp[i][j] = dp[i][j-1]，
//即此时与总体积不超过 i 的前 j-1 件物品组成的价值最大值等价。
//得到递推方程为 dp[i][j]=max(dp[i-w][j-1]+v, dp[i][j-1])
#include<iostream>
using namespace std;
int T,M;
int time_1[101];
int value[101];
int dp[1001][101];//dp[i][j]表示装前j种物品，时间不超过i的最大价值
int main(){
    cin>>T>>M;
    for(int i=1;i<=M;i++) cin>>time_1[i]>>value[i];
    for(int i=0;i<=T;i++) dp[i][0]=0; //初始化，装前0件物品，价值定为0，作为递归的初始条件
    for(int j=1;j<=M;j++){
        for(int i=T;i>=time_1[j];i--) dp[i][j]=max(dp[i][j-1],dp[i-time_1[j]][j-1]+value[j]);
        for(int i=time_1[j]-1;i>=0;i--) dp[i][j]=dp[i][j-1];
    }
    cout<<dp[T][M]<<endl;
    return 0;
}
