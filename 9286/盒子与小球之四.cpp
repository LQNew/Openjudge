//一开始用组合数学的思路去想这个问题，发现思路行不通！！
//本道题和poj 上的 Push Botton Lock的题目区别是，它是 n个不同的球投入m个不同的盒子中同时每个盒子至少含有K个球，
//而 poj 上的 Push Botton Lock 是 n个不同的球投入m个不同的盒子中同时每个盒子至少含有1个球，
//相较于 poj 上的 Push Botton Lock 题目是典型的第二类斯特灵数的求法，本道题是有些许改进，但实际上只是 (N,M,K)特定情况下的方案数 本道题比较经典，建议多多研读理解！
//f[i][j]=sum(f[i-k][j-1]*c[n-(i-k)][k])-- k: K-i
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int M,N,K;
long long c[16][16],f[16][16]; //f[i][j]表示 将i个球放入j个盒子的方案数
int main(){
    c[0][0]=1;
    for(int i=1; i<=15; i++)
    {
        c[i][0]=c[i][i]=1;//组合数的初始化
        for(int j=1; j<i; j++) c[i][j]=c[i-1][j-1]+c[i-1][j]; //递归求出组合数
    }
    while(cin>>N>>M>>K){
        if(N==0&&M==0&&K==0) break;
        memset(f,0,sizeof(f)); //将状态二维数组初始化
        for(int i=K;i<=N;i++) f[i][1]=c[N][i];
        for(int i=K;i<=N;i++){
            for(int j=2;j<=M;j++){
                for(int t=K;t<=i;t++){
                    if(i-t>=0) f[i][j]+=f[i-t][j-1]*c[N-i+t][t];
                }
            }
        }
        cout<<f[N][M]<<endl;
    }
    return 0;
}
