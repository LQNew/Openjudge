//给出所有结点之间彼此的距离，试求出从1号节点到达其他节点的最短路径长度
//这是典型的单源最短路径问题，可以采用Dijkstra算法，该算法的实现非常经典，可作为模板程序记忆理解！！
#include<iostream>
#include<vector>
using namespace std;
int N,M;
int a,b,c;
struct E
{
    int next;
    int cost;
};
vector<E> edge[101];
bool mark[101];
int Dis[101];
int main()
{
    while(cin>>N>>M)
    {
        if(N==0&&M==0) break;
        for(int i=0;i<N;i++) edge[i].clear();
        for(int i=0;i<M;i++) //针对无向图的临接矩阵构造方法~
        {
            cin>>a>>b>>c;
            E tmp;
            tmp.cost=c;
            tmp.next=b;
            edge[a].push_back(tmp); //构造临接矩阵
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        for(int i=1;i<=N;i++)
        {
            Dis[i]=-1;
            mark[i]=false;
        }
        Dis[1]=0; //如果最近的点为结点1，设置该点与自身距离为0
        mark[1]=true;
        int newP=1;
        for(int i=1;i<N;i++) //每一次的循环找出一个从1出发到达的最近的节点的路径
        {
            for(int j=0;j<edge[newP].size();j++) //找出经过中间结点到达目标节点的所有路径，并计算路径值
            {
                int t=edge[newP][j].next;
                int cost=edge[newP][j].cost;
                if(mark[t]==true) continue;//已经位于最短路径集合中了
                if(Dis[t]==-1||Dis[t]>Dis[newP]+cost) //将每一次经过当前中间节点中转得到的距离比对，找出从1节点到该节点目前的最小值
                    Dis[t]=Dis[newP]+cost;
            }
            int min_1=99999999;
            for(int j=1;j<=N;j++)//找出本次循环时最短路径对应的节点
            {
                if(mark[j]==true) continue;
                if(Dis[j]==-1) continue;
                if(Dis[j]<min_1)
                {
                    min_1=Dis[j];
                    newP=j;
                }
            }
            mark[newP]=true;
        }
        cout<<Dis[N]<<endl;
    }
}
