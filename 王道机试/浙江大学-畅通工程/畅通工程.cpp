/*
    省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）
*/
//分析：题目中给出的是城镇之间连通的节点，我们要做的是当每个节点彼此存在直接或间接的连接关系时，便将它们放在同一个集合之内，通过此种分析可以
//      轻易得出这是一个并查集问题，即将所有存在连接关系的节点放在一棵树下，每棵树的树高最多为两层，这样保证了访问根节点时的效率！
#include<iostream>
using namespace std;
int M,N;
int ans;
int Tree[1001];
int a,b;
int Find_root(int x) //找出每个节点当前的最原始的祖先节点！并将当前节点的双亲节点直接设为祖先节点
{
    if(Tree[x]==-1) return x;
    else
    {
        int tmp=Find_root(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
int main()
{
    while(cin>>N)
    {
        if(N==0) break;
        cin>>M;
        for(int i=1;i<=N;i++)
            Tree[i]=-1;
        for(int i=0;i<M;i++) //输入边，并构造并查集树
        {
            cin>>a>>b;
            a=Find_root(a);
            b=Find_root(b);
            if(a!=b)
                Tree[a]=b;//合并两个节点的根节点，得到一个合并后的集合
        }
        ans=0;
        for(int i=1;i<=N;i++) //最后就是查找最终有多少棵树，即双亲节点为-1的节点，然后由于两点成边，所以双亲节点为-1的节点总数-1即为求得的应额外搭建的边
        {
            if(Tree[i]==-1)
                ans++;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
