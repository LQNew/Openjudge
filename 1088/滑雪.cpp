/*
    1  2  3  4 5
   16 17 18 19 6
   15 24 25 20 7
   14 23 22 21 8
   13 12 11 10 9
   一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。
   在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

   输入：
   输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
   输出：
   输出最长区域的长度。

   分析：利用DP算法，从矩阵中的每一点出发均去寻找最长的路径  可以采用递归的思路去解决此问题~
*/
//此道题用递归的思想，递归这一块代码实现理解得不够深刻，还需多多思考！！
#include<iostream>
#include<string.h>
const int N=100;
using namespace std;
int R,C;
int node[N][N];//先设置一个矩阵用于存储山峰的高度，山峰的高度值将初始化为一个极大的值 >10000
int store[N][N];
int one_step[4][2]={
    {-1,0},
    {1 ,0},
    {0 ,1},
    {0,-1}
};//左、右、上、下四个方向

bool judge(int i,int j) //判别节点操作是否会超界
{
    return (i>=0&&i<R&&j>=0&&j<C);
}

int dp(int i,int j) //动态规划中递归的思路，为了减少时间复杂度，会另开一个数组用于存储每个节点当前所计算出的最长路径长度
{
    if(store[i][j]>0) return store[i][j];
    for(int k=0;k<4;k++)
    {
        if(judge(i+one_step[k][0],j+one_step[k][1])&&node[i][j]>node[i+one_step[k][0]][j+one_step[k][1]]) //向某一方向移动不超界且可以向下滑动时
        {
            if(store[i][j]<dp(i+one_step[k][0],j+one_step[k][1])+1) //在四个方向如果不超界的条件下，判别往哪个方向能得到最大的路径长度
               store[i][j]=dp(i+one_step[k][0],j+one_step[k][1])+1;
        }
    }
    return store[i][j];

}

int main()
{
    cin>>R>>C;
    memset(store,0,sizeof(store));
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
            cin>>node[i][j];
    }
    int max_len=0;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            max_len=max(max_len,dp(i,j)); //每次比对递归运算得到的路径长度值，并用一变量存储当前最长的路径值
    cout<<max_len+1<<endl;
    return 0;

}
