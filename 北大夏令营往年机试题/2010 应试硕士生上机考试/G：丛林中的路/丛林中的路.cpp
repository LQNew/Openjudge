//典型题，最小生成树问题
#include<iostream>
#include<cstring>
using namespace std;
int n;
struct Node{
    int a;
    int b;
    int cost;
};
Node node[100];
int tree[26];
int k;
int cost;
char a;
char b;

int find_root(int x){
    if(tree[x]==-1) return x;
    else{
        int tmp=find_root(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}

int compare(const void* a, const void* b){
    Node*p1;
    Node*p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return (*p1).cost-(*p2).cost;
}
int main(){
    while(cin>>n){
        if(n==0) break;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            cin>>a;
            cin>>k;
            for(int i=0;i<k;i++){
                cin>>b>>cost;
                node[cnt].a=int(a-'A');
                node[cnt].b=int(b-'A');
                node[cnt].cost=cost;
                cnt++;
            }
        }
        qsort(node,cnt,sizeof(Node),compare);
       // for(int i=0;i<cnt;i++) cout<<char(node[i].a+'A')<<' '<<char(node[i].b+'A')<<node[i].cost<<endl;
        memset(tree,-1,sizeof(tree));
        int ans=0;
        for(int i=0;i<cnt;i++){
            int root1=find_root(node[i].a);
            int root2=find_root(node[i].b);
            if(root1!=root2){ //为了避免成环！
                tree[root1]=root2;
                ans+=node[i].cost;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
