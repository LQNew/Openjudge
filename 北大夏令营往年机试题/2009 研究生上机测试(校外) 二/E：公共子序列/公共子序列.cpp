//最长公共子序列，模板题，要熟悉！！
#include<iostream>
#include<cstring>
using namespace std;
char str1[210];
char str2[210];
int dp[201][201];
int main(){
    while(cin>>str1>>str2){
        for(int i=0;i<strlen(str1);i++) dp[i][0]=0;
        for(int i=0;i<strlen(str2);i++) dp[0][i]=0;
        for(int i=0;i<strlen(str1);i++){
            for(int j=0;j<strlen(str2);j++){
                if(str1[i]==str2[j]){
                    dp[i+1][j+1]=max(dp[i][j]+1,dp[i][j+1]);
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i+1][j+1]);
                }
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        cout<<dp[strlen(str1)][strlen(str2)]<<endl;
    }
    return 0;
}
