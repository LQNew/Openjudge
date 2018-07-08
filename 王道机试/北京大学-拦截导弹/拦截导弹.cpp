/*
    但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭，
    并观测到导弹依次飞来的高度，请计算这套系统最多能拦截多少导弹。拦截来袭导弹时，必须按来袭导弹袭击的时间顺序，不允许先拦截后面的导弹，再拦截前面的导弹。
*/
//分析：这道题是典型的最长递增子序列问题，从左至右按序找出当前符合条件的最大序列并对应标识出来，难度不大，主要应该理解最长递增子序列的思路！！
#include<iostream>
#include<cstring>
using namespace std;
int k;//敌国导弹的数目
int a[26];//记录导弹的高度
int F[26];//对于每一个次序，可拦截的最大导弹数
int main(){
    while(cin>>k){
        for(int i=1;i<=k;i++) cin>>a[i];
        memset(F,0,sizeof(int)*26);
        int max_final=1;
        F[1]=1;
        for(int i=2;i<=k;i++){
            int max_1=1;
            for(int j=1;j<i;j++){
                if(a[j]>=a[i]){
                    if(F[j]+1>max_1) max_1=F[j]+1;
                }
            }
            F[i]=max_1;
            if(max_1>max_final) max_final=max_1;
        }
        cout<<max_final<<endl;
    }
    return 0;
}
