#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main(){
    queue<int> q;
    memset(flow,0,sizeof(flow));
    for(;;){
        memset(a,0,sizeof(a));
        a[s]=INF;
        q.push(s);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v=1;v<=n;v++){
                if(!a[v]&&cap[u][v]>flow[u][v]){
                    p[v]=u; q.push(v);
                    if(a[v]<(cap[u][v]-flow[u][v]))
                        a[v]=a[v];
                    else
                        a[v]=cap[u][v]-flow[u][v];
                }
            }
        }
        if(a[t]==0) break;
        for(int u=t;u!=s;u=p[u]){
            flow[p[u]][u]+=a[t];
            flow[u][p[u]]-=a[t];
        }
        f+=a[t];
    }
    return 0;
}
