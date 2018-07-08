/*
    省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），
    并要求铺设的公路总长度为最小。请计算最小的公路总长度。
*/
//分析：这是道典型的最小生成树问题，利用Kruskal算法,每次找到现在图中节点间最短路径，判别该边是否已划分到最短路径的集合中
//从这个角度思考分析会发现，这就是个排序+并查集问题，每次找到不属于当前集合的当前最短边，就将其并入最短路径中，并记录该权值
//最后权值之和便是最短生成树的权值~
#include<iostream>
using namespace std;
int N;
int Tree[101];
int a,b;
int ans;

struct Node
{
    int a;
    int b;
    int cost;
};
Node node[5000];

int compare(const void*a,const void*b) //针对结构体的快速排序
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    return (*p).cost-(*p1).cost;
}

int find_Root(int x) //找到当前结点的祖先结点
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
    while(cin>>N)
    {
        if(N==0) break;
        ans=0;
        for(int i=1;i<=N;i++)
            Tree[i]=-1;
        for(int i=0;i<(N*(N-1))/2;i++)
            cin>>node[i].a>>node[i].b>>node[i].cost;
        qsort(node,(N*(N-1))/2,sizeof(Node),compare);
        for(int i=0;i<(N*(N-1))/2;i++) //遍历所有结构体，找到最小生成树
        {
            a=find_Root(node[i].a);
            b=find_Root(node[i].b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=node[i].cost;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
