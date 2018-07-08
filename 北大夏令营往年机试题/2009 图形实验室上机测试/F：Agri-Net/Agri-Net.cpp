//模板题，直接套kruscal 框架，但是此处模板题我有一处写错了，wa了两次后才发现，就是找集合的终结点时再更新写得有问题，模板题需要反复地记忆，保证临场要能快速打出来！
#include<iostream>
#include<cstring>
using namespace std;
int N;
int map1[101][101];
struct Node{
    int x;
    int y;
    int cost;
};
Node node[10000];
int tree[101];
int compare(const void*a, const void* b){
    Node*p1;
    Node*p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return (*p1).cost-(*p2).cost;
}
int find_root(int x){
    if(tree[x]==-1) return x;
    else{
        int tmp=find_root(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}
int main(){
    while(cin>>N){
        int cnt=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++) cin>>map1[i][j];
        }
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(map1[i][j]){
                    node[cnt].x=i;
                    node[cnt].y=j;
                    node[cnt].cost=map1[i][j];
                    cnt++;
                }
            }
        }
        memset(tree,-1,sizeof(tree));
        qsort(&node[0],cnt,sizeof(Node),compare);
        int ans=0;
        //此处代码一开始码错了，这种低级错误不要再犯！！
        for(int i=0;i<cnt;i++){
            int a=find_root(node[i].x); //找到a对应的集合的终点
            int b=find_root(node[i].y); //找到b对应的集合的终点
            if(a!=b){
                tree[a]=b;
                ans+=node[i].cost;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
