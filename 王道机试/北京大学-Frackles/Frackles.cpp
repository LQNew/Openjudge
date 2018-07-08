//给出各个点坐标，试将所有点都可以连接起来，并且总共的距离值是最小的
//这道题和浙大的还是畅通工程思路是相似的，只需要先把各个点之间彼此的距离值算出来，然后用结构体存储，之后就转换为了还是畅通工程这道问题
//本道题用到了iomanip库的setprecision()函数以及fixed；cstring库的memset()函数；cmath库的sqrt()函数
#include<iostream>
#include <cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int n;
float ans;
int a,b;
int Tree[101]; //存储节点的祖先节点
struct Node
{
    int a;
    int b;
    float cost;
};
Node node[5000];

struct Point //记录节点坐标
{
    float x;
    float y;
};
Point point[101];

int compare(const void*a,const void*b) //针对结构体的快速排序
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    if((*p).cost>(*p1).cost)
        return 1;
    else if((*p).cost<(*p1).cost)
        return -1;
    else
        return 0;
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
    while(cin>>n)
    {
        ans=0;
        memset(Tree,-1,sizeof(Tree[0])*(n+1));//数组的初始化
        for(int i=1;i<=n;i++)
            cin>>point[i].x>>point[i].y;
        int k=0;
        for(int i=1;i<=n;i++)//构建结构体node
        {
            for(int j=i+1;j<=n;j++)
            {
                node[k].a=i;
                node[k].b=j;
                node[k].cost=sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));//获取节点之间彼此的距离
                k++;
            }
        }
        qsort(node,(n*(n-1))/2,sizeof(Node),compare);
        /*for(int i=0;i<(n*(n-1))/2;i++) //遍历所有结构体，找到最小生成树
            cout<<node[i].a<<" "<<node[i].b<<" "<<node[i].cost<<endl;
        */
        for(int i=0;i<(n*(n-1))/2;i++) //遍历所有结构体，找到最小生成树
        {
            a=find_Root(node[i].a);
            b=find_Root(node[i].b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=node[i].cost;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;//设置小数点后两位输出
    }
    return 0;
}
