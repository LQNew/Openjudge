/*
    给出两个字符串，给出最长公共子字符串包含的字符数目
*/
//典型的最长公共子序列题目，主要还是其中的递归形式要理解，这是常规的套路，还是要熟悉熟悉！！
#include<iostream>
#include<cstring>
using namespace std;
char str1[101];//输入的字符串1
char str2[101];//输入的字符串2
int dp[101][101];//用于记录中间的最长公共子序列的字符个数
int main(){
    while(cin>>str1>>str2){
        for(int i=0;i<101;i++){ //初始化
            for(int j=0;j<101;j++) dp[i][j]=0;
        }
        int len1=strlen(str1);
        int len2=strlen(str2);
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else{
                    if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1];
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
