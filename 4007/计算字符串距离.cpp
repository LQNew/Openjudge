//本道题是编辑距离问题，然而我感觉AC的代码有问题，此处是我觉得正确但是WA的代码：
//首先定义这样一个函数——edit(i, j)，它表示第一个字符串的长度为i的子串到第二个字符串的长度为j的子串的编辑距离。
//显然可以有如下动态规划公式。
// if i == 0 且 j == 0，edit(i, j) = 0
// if i == 0 且 j > 0，edit(i, j) = j
// if i > 0 且j == 0，edit(i, j) = i
// if i ≥ 1  且 j ≥ 1 ，edit(i, j) == min{ edit(i-1, j) + 1, edit(i, j-1) + 1, edit(i-1, j-1) + f(i, j) }，
// 当第一个字符串的第i个字符不等于第二个字符串的第j个字符时，f(i, j) = 1；否则，f(i, j) = 0。
#include<iostream>
#include<cstring>
using namespace std;
int n;
int flag;
char str1[1001],str2[1001];
int dp[1001][1001];//dp[i][j]表征str1的前i个字符和str2的前j个字符的编辑距离
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str1>>str2;
        for(int i=0;i<=strlen(str1);i++) dp[i][0]=i; //初始化编辑距离
        for(int j=0;j<=strlen(str2);j++) dp[0][j]=j;
        for(int i=1;i<=strlen(str1);i++){
            for(int j=1;j<=strlen(str2);j++){
                if(str1[i]==str2[j]) flag=0;
                else flag=1;
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+flag);
            }
        }
        cout<<dp[strlen(str1)][strlen(str2)]<<endl;
    }
    return 0;
}
