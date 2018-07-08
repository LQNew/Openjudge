//已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。
//分析：本道题乍一看无处下手，不过仔细分析后可以认为此道题就是最大连续子序列和的变种问题，因为矩阵是二维的，不妨采用行压缩的方式，每次选出i,j。
//然后求出从第i行到第j行内所有的列值压缩为一维形式，求出此段的最大连续子序列和，即为横跨第i行到第j行的最大矩阵~
//枚举出所有的i，j的情况比对就可以得到最终的最大子矩阵！
#include<iostream>
#include<cstring>
using namespace std;
int matrix[101][101];
int a[101];
int N;

int calculate_1(){ //计算最大连续子序列和的模板
    int local_sum=a[1];
    int b=0;
    for(int i=1;i<=N;i++){
        if(b>0) b+=a[i];
        else b=a[i];
        if(b>local_sum) local_sum=b;
    }
    return local_sum;
}
int main(){
    cin>>N;
    int max1=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) cin>>matrix[i][j];
    }
    for(int i=1;i<=N;i++){
        memset(a,0,sizeof(a));
        for(int j=i;j<=N;j++){
            for(int k=1;k<=N;k++) a[k]+=matrix[j][k];//计算出从i行到j行之间的每一列的数值之和，压缩至一维
            max1=max(max1,calculate_1());
        }
    }
    cout<<max1<<endl;
    return 0;
}
