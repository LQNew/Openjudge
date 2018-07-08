//给出所有结点之间彼此的距离，试求出各个节点之间的最短路径
//这是一道最基本最原始的最短路问题，就是套用Floyd算法模板做题，本程序是一个模板程序，一定要记住！！
#include<iostream>
using namespace std;
int N,M;
int A,B,C;
int ans[101][101]; //二维数组,其初始值即为该图的邻接矩阵
int main()
{
    while(cin>>N>>M)
    {
        if(N==0&&M==0) break;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
                ans[i][j]=-1;
            ans[i][i]=0;
        }
        for(int i=0;i<M;i++) //构建图的临接矩阵
        {
            cin>>A>>B>>C;
            ans[A][B]=ans[B][A]=C;
        }
        for(int k=1;k<=N;k++) //套用Floyd算法，求出所有结点间彼此的最短路径
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    if(ans[i][k]==-1||ans[k][j]==-1||i==j||i==k||j==k) continue; //如果当前 i,k或者k,j之间不存在路径，就没有意义，或者 i==j，那么就是一个点或者i==k或者j==k这些都不存在意义可言
                    if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
                        ans[i][j]=ans[i][k]+ans[k][j];
                }
            }
        }
        cout<<ans[1][N]<<endl;
    }
    return 0;
}
