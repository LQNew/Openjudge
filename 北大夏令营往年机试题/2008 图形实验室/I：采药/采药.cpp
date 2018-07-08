//0/1 背包问题，算是水题...
#include<iostream>
using namespace std;
int T;
int M;
int time1[101];
int value[101];
int dp[1001];
int main(){
    cin>>T>>M;
    for(int i=1;i<=M;i++) cin>>time1[i]>>value[i];
    for(int i=0;i<=T;i++) dp[i]=0;
    for(int i=1;i<=M;i++){
        for(int t=T;t>=time1[i];t--) dp[t]=max(dp[t-time1[i]]+value[i],dp[t]);
    }
    int ans=0;
    for(int i=1;i<=T;i++) ans=max(dp[i],ans);
    cout<<ans<<endl;
    return 0;
}
