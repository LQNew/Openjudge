//典型的最短路径问题，题目难度不大，但是单源 dijkstra算法码起来有点复杂，所以这类代码要多码！以防临场码不出来！
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
int T,N;
struct Edge{
    int next; //指向的下一个节点
    int cost;
};
vector<Edge> edge[1001];
int Dist[1001];
bool mark[1001];
int dst1,dst2;
int cost1;
int main(){
    cin>>T>>N;
    for(int i=1;i<=N;i++) edge[i].clear(); //把所有的边连接均清除
    for(int i=0;i<T;i++){ //构造临界图
        cin>>dst1>>dst2>>cost1;
        Edge tmp;
        tmp.cost=cost1;
        tmp.next=dst2;
        edge[dst1].push_back(tmp);
        tmp.next=dst1;
        edge[dst2].push_back(tmp);
    }
    memset(Dist,-1,sizeof(Dist));
    memset(mark,0,sizeof(mark));
    Dist[N]=0;
    mark[N]=true;
    int newP=N;
    for(int i=0;i<N;i++){
        for(int j=0;j<edge[newP].size();j++){ //从新增的节点出发，看有没有什么路径可以更新
            int t=edge[newP][j].next;
            int c=edge[newP][j].cost;
            if(mark[t]) continue; //该节点已经为检测出最短路径的集合中，则不再查
            if(Dist[t]==-1||Dist[t]>Dist[newP]+c){
                Dist[t]=Dist[newP]+c;
            }
        }
        int min1=INF;
        for(int j=1;j<=N;j++){ //找到当前所有剩余的路径中最短的路径
            if(mark[j]) continue;
            if(Dist[j]==-1) continue;
            if(Dist[j]<min1){
                min1=Dist[j];
                newP=j;
            }
        }
        mark[newP]=true;
    }
    cout<<Dist[1]<<endl;
}
