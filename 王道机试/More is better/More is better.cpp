/*
    若 A 与 B 是朋友，B 与 C 是朋友，那么我们也认为 A 与 C 是朋友。在给出这 N 对朋友关系后，要求我们找出一个最大（人数最多）的集合，该集
    合中任意两人之间都是朋友或者该集合中只有一个人，输出该最大人数。
*/
//分析：还是并查集问题，只不过又要求求出并查集每个树对应的节点数目，此处在构建并查集时可以对于每个当前的树节点累加它的sum值，就像是一个阶层机制
//      逐层向上传递值合并，最后剩余的树节点就对应该树的总节点数目
#include<iostream>
using namespace std;
int Tree[10000001];
int sum[10000001];
int A,B;
int pairs,ans;
int find_Root(int x) //找出节点的祖先节点
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
    while(cin>>pairs)
    {
        for(int i=1;i<10000001;i++)
        {
            Tree[i]=-1;
            sum[i]=1;
        }
        for(int i=0;i<pairs;i++)
        {
            cin>>A>>B;
            A=find_Root(A);
            B=find_Root(B);
            if(A!=B)
            {
                Tree[A]=B;
                sum[B]+=sum[A];//获取节点总数目
            }
        }
        ans=0;
        for(int i=1;i<10000001;i++)
        {
            if(Tree[i]==-1&&sum[i]>ans)
                ans=sum[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
