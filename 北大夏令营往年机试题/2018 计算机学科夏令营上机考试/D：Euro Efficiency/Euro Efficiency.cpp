//典型的背包问题，题目本身出得很是繁杂，让人不易读懂题目，但本质上难度不是很大
//笼统地说，其实本质上就是给一个数，然后给定一些固定的数，让该数只能通过这些固定的数进行加减运算求得，且运算的次数要最少
//仔细地分析后，是正负完全背包问题的糅合，求最小值
//对于完全负背包是逆序，完全正背包是正序，仔细分析可以知道目的就是：每次能够利用到之前运算所得的最小或最大值
//同时对于0-1背包需要了解的是：0-1背包是逆序，因为每个物体只能用到一次！这二者的细节区分一定要了解！
#include<iostream>
#include<iomanip>
using namespace std;
const int INF=0x7fffffff;
int maxn=5000;
int cases;
int a[6];
int dp[5001];
int main(){
    cin>>cases;
    for(int i=0;i<cases;i++){
        for(int i=0;i<6;i++) cin>>a[i];
        for(int i=0;i<=maxn;i++) dp[i]=INF; //初始化，注意用memset初始化时只可以初始化为0或-1，其他均不可以
        dp[0]=0;
        for(int i=0;i<6;i++){
            for(int j=a[i];j<=maxn;j++) dp[j]=min(dp[j],dp[j-a[i]]+1); //完全正背包，仅算加的时候
        }
        for(int i=0;i<6;i++){
            for(int j=maxn-a[i];j>=0;j--) dp[j]=min(dp[j],dp[j+a[i]]+1); //完全负背包，仅算减的时候
        }
        int max1=-1;
        int s=0;
        for(int i=1;i<=100;i++){
            if(dp[i]>max1) max1=dp[i];
            s+=dp[i];
        }
        cout<<fixed<<setprecision(2)<<double(s)/100.0<<' '<<max1<<endl;
    }
    return 0;
}
