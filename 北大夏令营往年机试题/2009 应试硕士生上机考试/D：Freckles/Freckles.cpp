//最下生成树的变种题，题目难度不大，但是本处自己挖了个坑，就是在compare函数的书写上，因为比较的是double型数，但compare返回的是int型数，所以出了些问题，
//对于double型数的返回情况书写，应该自己去写返回条件！！本道题目前的解法可以算作样例学习！
#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int n;
struct Node{
    double x;
    double y;
};
struct Edge{
    int id1;
    int id2;
    double cost;
};
Node node[100];
Edge edge[10000];
int tree[100];

int find_root(int x){
    if(tree[x]==-1) return x;
    else{
        int tmp=find_root(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}

int compare(const void* a, const void* b){
    Edge*p1;
    Edge*p2;
    p1=(Edge*)a;
    p2=(Edge*)b;
    if((*p1).cost>(*p2).cost) return 1; //本道题有一个细节需要注意！就是因为本处是double型运算，所以返回如果为int型的话一些double型转化会出问题，所以关于double型快排的书写一定要谨慎！
    else return -1;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>node[i].x>>node[i].y;
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            edge[cnt].id1=i;
            edge[cnt].id2=j;
            edge[cnt].cost=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
            cnt++;
        }
    }
    qsort(&edge[0],cnt,sizeof(Edge),compare);
    memset(tree,-1,sizeof(tree));
    double ans=0.0;
    for(int i=0;i<cnt;i++){
        int root1=find_root(edge[i].id1);
        int root2=find_root(edge[i].id2);
        if(root1!=root2){ //为了避免成环！
            tree[root1]=root2;
            ans+=edge[i].cost;
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
