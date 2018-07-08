/*
    N个城市，标号从0到N-1，M条道路，第K条道路（K从0开始）的长度为2^K，求编号为0的城市到其他城市的最短距离，N(2<=N<=100);M(M<=500)
*/
//分析：本道题是典型的最短路径问题，但因为有2的N次方存在，所以要么用大数运算，不过大数运算求解思路并没有彻底理清楚...
//故而采用了最小生成树的算法，分析可知2^n>Σ2^k，所以可以知道 对于新的路径，如果两个节点均在一个集合下，那么这两个点之间的路径长度肯定有比这个新的路径小的存在
//对于两个不在同一集合的端点，说明该两个集合内的点，它们之前彼此没有路径连接，那么此时两个集合下的点之间的距离一定都是最短距离，所以需要遍历两个集合，
//将所有彼此二者关联的点计算出路径~
//本道题思路较难，对于图论的考查也是比较深入，一定要明白意图，对症下药！！
#include<iostream>
using namespace std;
int store[500];
int Tree[100];
int value;
int N,M;
int x,y,a,b;
long long ans[100][100]; //二维数组,其初始值即为该图的邻接矩阵
int find_Root(int x)
{
    if(Tree[x]==-1) return x;
    else
    {
        int tmp=find_Root(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
int main()
{
    value=1;
    store[0]=1;
    for(int i=1;i<500;i++) //将2的500次方的值的后五位用一维数组存储下来~
    {
        value*=2;
        value%=100000;
        store[i]=value;
    }
    while(cin>>N>>M)
    {
        for(int i=0;i<N;i++){ //初始化，一开始所有的路径出始化为-1，同一节点处的距离初始化为-1
            Tree[i]=-1;
            for(int j=0;j<N;j++){
                ans[i][j]=-1;
            }
            ans[i][i]=0;
        }

        for(int i=0;i<M;i++) //构建图的临接矩阵
        {
            cin>>a>>b;
            x=find_Root(a);
            y=find_Root(b);
            if(x==y) continue;
            //此处思路要细细理解！！
            for(int initial=0;initial<N;initial++) //两个集合内的点之间计算彼此的距离~
            {
                if(x==find_Root(initial))
                {
                    for(int ending =0;ending<N;ending++)
                    {
                        if(y==find_Root(ending))
                        {
                            ans[ending][initial]=ans[initial][a]+ans[ending][b]+store[i];
                            ans[initial][ending]=ans[ending][initial];
                        }
                    }
                }
            }
            Tree[y]=x;
        }

        for(int j=1;j<N;j++)
            cout<<ans[0][j]%100000<<endl;
    }
    return 0;
}
