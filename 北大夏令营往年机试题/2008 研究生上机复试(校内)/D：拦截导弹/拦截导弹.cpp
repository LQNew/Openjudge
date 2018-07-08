//最长递增子序列的相似题，简单动归思路
#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
int k;
int a[26];
int dp[26];
int main(){
    cin>>k;
    for(int i=1;i<=k;i++) cin>>a[i];
    a[0]=INF;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<k;i++){
        for(int j=i+1;j<=k;j++){
            if(a[j]<=a[i]) dp[j]=max(dp[j],dp[i]+1);
            else dp[j]=dp[j];
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
