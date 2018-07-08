//动归，最长递增子序列的变种题型
#include<iostream>
using namespace std;
int k;
int a[26];
int dp[30];
int main(){
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        dp[i]=1;
    }
    for(int i=1;i<k;i++){
        for(int j=i+1;j<=k;j++){
            if(a[j]<=a[i]) dp[j]=max(dp[j],dp[i]+1);
        }
    }
    int max1=0;
    for(int i=1;i<=k;i++){
        max1=max(dp[i],max1);
    }
    cout<<max1<<endl;
    return 0;
}
