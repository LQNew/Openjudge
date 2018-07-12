//只写了一个 Dijkstra算法模板，没有考虑题意，orz..因为北大夏令营凉了，弃题不再刷！
//本道题并没有完全解决！有需求的同学建议自己在网上扒拉些解法吧！
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct Edge{
    int next;
    int t;
};
int N;
int M;
int a,b,t;
int add_1;
int Dis[601];
bool mark[601];
vector<Edge> edge[601];
int main(){
    while(cin>>N){
        if(N==0) break;
        cin>>M;
        for(int i=1;i<=N;i++){
            while(!edge[i].empty()) edge[i].clear();
        }
        memset(&Dis[1],-1,sizeof(int)*N); //距离初始化为-1
        memset(&mark[1],0,sizeof(bool)*N); //节点标识都初始化为非访问
        for(int i=0;i<M;i++){
            cin>>a>>b>>t;
            Edge tmp;
            tmp.t=t;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        for(int i=1;i<=N;i++) cin>>add_1;
        Dis[1]=0;
        mark[1]=true;
        int newp=1;
        for(int i=0;i<N-1;i++){
            for(int j=0;j<edge[newp].size();j++){
                if(mark[Dis[edge[newp][j].next]]) continue;
                if(Dis[edge[newp][j].next]==-1||(Dis[edge[newp][j].next]>Dis[newp]+edge[newp][j].t)) Dis[edge[newp][j].next]=Dis[newp]+edge[newp][j].t;
            }
            int min1=0x7fffffff;
            for(int i=1;i<=N;i++){
                if(mark[i]||Dis[i]==-1) continue;
                if(Dis[i]<min1){
                    min1=Dis[i];
                    newp=i;
                }
            }
            if(min1==0x7fffffff) continue;
            mark[newp]=true;
        }
        if(Dis[2]==-1) cout<<-1<<endl;
        else cout<<Dis[2]<<endl;
    }
    return 0;
}
