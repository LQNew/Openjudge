//给出搬寝室的要求，本处的动归方程不是特别容易相出来，主要是基于两点：
//1.选定的最优方案中，任选两对组合，其配对情况必为重量最大物品和重量次大物品为一对、重量最小物品和重量次小物品为一对，不存在交叉组合的情况
//2.对于每对组合，配对必须是相邻重量的物品配对，否则属于交叉组合没有意义
//基于以上二点可以去构造递归方程，首先选择一个二元方程组去表示递归的状态，本处dp[i][j]的设置含义也很有意思，指前j个物品中选出i对物品时最小的疲劳度
//如果j=2*i,那么j和j-1可以配对；而如果 j>2*i，那么错过就错过了，dp[i][j]=dp[i][j-1]
//故综上，动归方程为 dp[i][j]=min{dp[i][j-1],dp[i-1][j-2]+(weight[j]-weight[j-1])^2

#include<iostream>
using namespace std;
const int Max=2000;
int dp[Max/2][Max]; //dp[i][j]表示在前j个物品中选出i对物品时最小的疲劳度
int n,k;
int weight[Max];//记录每个物体的重量

int compare(const void *a,const void* b ){
    return *(int*)a - *(int*)b;
}

int main(){
    while(cin>>n>>k){
        for(int j=1;j<=n;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++) cin>>weight[i];
        qsort(&weight[1],n,sizeof(weight[0]),compare);
        //动归状态方程
        for(int i=1;i<=k;i++){
            for(int j=2*i;j<=n;j++){
                if(j>2*i) dp[i][j]=dp[i][j-1];
                else{
                    dp[i][j]=dp[i-1][j-2]+(weight[j-1]-weight[j])*(weight[j-1]-weight[j]);
                }
            }
        }
        cout<<dp[k][n];
    }
    return 0;
}
