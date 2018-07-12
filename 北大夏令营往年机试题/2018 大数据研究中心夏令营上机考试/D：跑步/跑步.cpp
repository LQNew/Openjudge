/*
    别人大神想出的DP解法，我这渣渣也就只能看看学学...
    用dp[i][j]表示第i分钟，疲劳值为j的最大距离。
    首先考虑第i分钟休息问题：①上次已经疲劳为0，这次又休息。dp[i][0]=dp[i-1][0]. ②上次疲劳为k。dp[i][0]=max(dp[i][0],dp[i-k][k])，其中i-k>0
    然后考虑第i分钟跑步问题 dp[i][j]=dp[i-1][j-1]+d[i]。
    这样所有状态就推完了。最后ans=dp[n][0]。
*/
//大神以疲劳值为0时的状态开始推，思路很抽象，我并没有特别get到大神的思路...但是感觉这是一类题，可能这类题见多了就有思路了orz...
#include<iostream>
using namespace std;
int d[10001],dp[10001][501];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0];
        for(int j=1;j<=m&&i-j>0;j++) dp[i][0]=max(dp[i][0],dp[i-j][j]);
        for(int j=1;j<=m;j++)
            dp[i][j]=dp[i-1][j-1]+d[i];
    }
    cout<<dp[n][0]<<endl;
}
