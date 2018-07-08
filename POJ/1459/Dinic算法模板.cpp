#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define maxn 1005
#define inf 0x3f3f3f3f
int first[maxn],nxt[maxn<<1],to[maxn<<1],pre[maxn<<1],e,flow[maxn<<1],cap[maxn<<1];
//int a[maxn],fa[maxn];
bool vis[maxn];
int level[maxn],cur[maxn];
void add(int u,int v,int c){
     to[e]=v;
     pre[e]=u;
     flow[e]=0;
     cap[e]=c;
     nxt[e]=first[u];
     first[u]=e++;
}
bool bfs(int s,int t){
   memset(vis,0,sizeof vis);
   //memset(level,0,sizeof level);
   queue<int>q;
   level[s]=0;
   vis[s]=1;
   q.push(s);
   while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=first[u];~i;i=nxt[i]){
        int v=to[i],fl=flow[i],c=cap[i];
        if(!vis[v]&&c>fl){
            level[v]=level[u]+1;
            vis[v]=1;
            q.push(v);
        }
    }
   }
   return vis[t];
}
int dfs(int u,int t,int f){
     if(u==t)return f;
     for(int &i=cur[u];~i;i=nxt[i]){
         int v=to[i],fl=flow[i],c=cap[i];
         if(level[v]==level[u]+1&&c>fl){
            int d=dfs(v,t,min(c-fl,f));
            if(d>0){
                flow[i]+=d;
                flow[i^1]-=d;
                return d;
            }
         }
     }
     return 0;
}
int max_flow(int s,int t){
    int flow=0;
    while(bfs(s,t)){
      for(int i=1;i<=t;i++){
        cur[i]=first[i];
      }
      int temp=dfs(s,t,inf);
      //if(temp==0)break;
      //else
      flow+=temp;
    }
    return flow;
}
int main()
{
    int t;
    int n,m;
    int u,v,c;
    int tt=0;
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        e=0;
        memset(first,-1,sizeof first);
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&c);
            add(u,v,c);
            add(v,u,0);
        }
        printf("Case %d: %d\n",++tt,max_flow(1,n));
    }
}
