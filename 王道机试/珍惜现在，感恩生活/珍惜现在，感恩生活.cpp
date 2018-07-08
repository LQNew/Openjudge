/*
    为了挽救灾区同胞的生命，心系灾区同胞的你准备自己采购一些粮食支援灾区，现在假设你一共有资金 n 元，而市场有 m 种大米，每种大米都是袋装产品，
    其价格不等，并且只能整袋购买，每种大米的数目有限。请问：你用有限的资金最多能采购多少公斤粮食呢？
*/
//介绍多重背包问题，其介于 0-1 背包和完全背包之间：有容积为V 的背包，给定一些物品，每种物品包含体积 w、价值 v、和数量 k，求用该背包能装下的最大价值总量。
//与之前的背包问题都不同，每种物品可选的数量不再为无穷或者 1，而是介于其中的一个确定的数 k。与之前讨论的问题一样，我们可以将多重背包问题直接转化到 0-1 背包上去，
//即每种物品均被视为 k 种不同物品，对所有的物品求 0-1背包
//本道题的数据量较小，所以此处这个简单版本就是直接把k件物品视为k种物品展开得到的
#include<iostream>
using namespace std;
int C;
int n,m;
int weight_1,price_1,num1,cnt;
int weight[2001];
int price[2001];
int dp[101];
int main(){
    cin>>C;
    for(int i=0;i<C;i++){
        cin>>n>>m;
        cnt=1;
        for(int i=1;i<=m;i++){
            cnt+=num1;
            cin>>price_1>>weight_1>>num1;
            for(int i=cnt;i<cnt+num1;i++){
                weight[i]=weight_1;
                price[i]=price_1;
            }
        }
        for(int i=0;i<=n;i++) dp[i]=0;
        for(int j=1;j<=cnt-1;j++){
            for(int i=n;i>=price[j];i--) dp[i]=max(dp[i],dp[i-price[j]]+weight[j]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
