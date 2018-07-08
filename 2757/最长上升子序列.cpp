//最长递归子序列，算是比较简单的动态规划问题，就是每次都从前j-1个最大长度去比对，找出最大的长度，即为在第j位的最长子序列长度
//最后为了得出总共序列的最长子序列的长度，需要遍历每一位得到的最长子序列长度找到最长的那条就好~
//dp[1]=1
//dp[i]=max(1,dp[j]+1|dp[i]>dp[j]&&i>j)
#include<iostream>
using namespace std;
int N;
int a[1001];
int dp[1001];
int main(){
    while(cin>>N){
        for(int i=1;i<=N;i++) cin>>a[i];
        dp[1]=1;
        for(int i=2;i<=N;i++){
            int max1=1;
            for(int j=1;j<i;j++){
                if(a[i]>a[j]){
                    if(max1<dp[j]+1) max1=dp[j]+1;
                }
            }
            dp[i]=max1;
        }
        int ans=0;
        for(int i=1;i<=N;i++){
            if(ans<dp[i]) ans=dp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
