//改进版本的：于是我们采用一种更为有技巧性的拆分。将原数量为 k 的物品拆分为若干组，每组物品看成一件物品，其价值和重量为该组中所有物品的价值重量总和，
//每组物品包含的原物品个数分别为：为：1、2、4...2^c，其中 c 为使 k-(1+2+4+..+2^c)大于 0 的最大整数。 接着就是最后拆出来的一个数是 k-(1+2+4+..+2^c)
//这种类似于二进制的拆分，不仅将物品数量大大降低，同时通过对这些若干个原物品组合得到新物品的不同组合，可以得到 0 到 k 之间的任意件物品的价值重量和，大大减少了时间复杂度
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
        cnt=0;
        for(int i=1;i<=m;i++){
            cin>>price_1>>weight_1>>num1;
            int c=1;
            while(num1-c>0){
                num1-=c;
                cnt++;
                weight[cnt]=weight_1*c;
                price[cnt]=price_1*c;
                c*=2;
            }
            weight[++cnt]=weight_1*num1;
            price[cnt]=price_1*num1;
        }
        for(int i=0;i<=n;i++) dp[i]=0;
        for(int j=1;j<=cnt;j++){
            for(int i=n;i>=price[j];i--) dp[i]=max(dp[i],dp[i-price[j]]+weight[j]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
