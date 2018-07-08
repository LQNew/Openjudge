/*
    给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，要求输出起点到终点的最短距离及其花费.如果最短距离有多条路线，则输出花费最少的。
*/
//分析：典型的最短路径问题，只不过在最短路径上又加了最小花费的约束，不过只是在最短路径源代码上稍作修改就可以解决~
//Dijkstra程序极其经典，一定要多加理解！！
#include<iostream>
#include<vector>
using namespace std;
int N,M;
int a,b,d,p;
int s,t;
struct E
{
    int next;
    int cost;
    int money;
};
vector<E> edge[1001];
bool mark[1001];
int Dis[1001];
int money[1001];
int main()
{
    while(cin>>N>>M)
    {
        if(N==0&&M==0) break;
        for(int i=0;i<N;i++) edge[i].clear();
        for(int i=0;i<M;i++) //针对无向图的临接矩阵构造方法~
        {
            cin>>a>>b>>d>>p;
            E tmp;
            tmp.cost=d;
            tmp.money=p;
            tmp.next=b;
            edge[a].push_back(tmp); //构造临接矩阵
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        cin>>s>>t;
        for(int i=1;i<=N;i++)
        {
            Dis[i]=-1;
            money[i]=0;
            mark[i]=false;
        }
        Dis[s]=0; //如果最近的点为结点1，设置该点与自身距离为0
        money[s]=0;
        mark[s]=true;
        int newP=s;
        for(int i=1;i<N;i++) //每一次的循环找出一个从1出发到达的最近的节点的路径
        {
            for(int j=0;j<edge[newP].size();j++) //找出经过中间结点到达目标节点的所有路径，并计算路径值
            {
                int t=edge[newP][j].next;
                int cost=edge[newP][j].cost;
                int money_1=edge[newP][j].money;
                if(mark[t]==true) continue;//已经位于最短路径集合中了
                if(Dis[t]==-1||Dis[t]>Dis[newP]+cost) //将每一次经过当前中间节点中转得到的距离比对，找出从1节点到该节点目前的最小值
                {
                    Dis[t]=Dis[newP]+cost;
                    money[t]=money[newP]+money_1;
                }
                else if(Dis[t]==Dis[newP]+cost&&money[t]>money[newP]+money_1)
                    money[t]=money[newP]+money_1;
            }
            int min_1=999999999;
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
        cout<<Dis[t]<<" "<<money[t]<<endl;
    }
}
