//拓扑排序面向有向无环图的形式，若节点U经过若干条有向边后能够到达节点V，则在求得的序列中U必排在V之前，这样便可以得出一定得为有向无环图
//按照这种性质可以判定一张图是否为有向无环图。
//具体步骤，选择一个入度为0的节点，作为序列的第一个节点，将该点以及以该点为弧尾的所有边删除获得一个新图；
//再在新图上选择一个入度为0的节点，重复以上操作，直到所有的节点和边均被从图中删除，如果操作完成后仍存有入度不为0的节点，那么说明眼图中有环路，故而有原图不为有向无环图
//关于这种问题，难度不是很大，主要是熟悉stl库的操作，如stack、vector的基本操作！！以及拓扑排序的原理~
/*
    在一个 qq 群里有着许多师徒关系，如 A 是 B 的师父，同时 B是 A 的徒弟，一个师父可能有许多徒弟，一个徒弟也可能会有许多不同的师父。
    输入给出该群里所有的师徒关系，问是否存在这样一种非法的情况：以三个人为例，即 A 是 B 的师父，B 是 C 的师父，C 又反过来是 A 的师父。若我们将该群
    里的所有人都抽象成图上的结点，将所有的师徒关系都抽象成有向边（由师父指向徒弟），该实际问题就转化为一个数学问题——该图上是否存在一个环，即判断该图是否为有向无环图。
*/
//分析，典型的有向无环图判别问题，程序也是经典的程序，一定要熟悉！！
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N,M;
int a,b;
vector<int>edge[100];
stack<int>point;
int mark[100];
int main()
{
    while(cin>>N>>M){
        if(N==0&&M==0) break;
        for(int i=0;i<N;i++){
            edge[i].clear(); //清空临接链表
            mark[i]=0;//初始化入度信息，所有结点入度均为0
        }
        for(int i=0;i<M;i++){
            cin>>a>>b;
            mark[b]++;
            edge[a].push_back(b);
        }
        while(!point.empty()) point.pop(); //将栈全部弹空
        for(int i=0;i<N;i++){
            if(mark[i]==0) point.push(i); //将所有入度为0的节点压入栈中
        }
        int cnt=0;
        while(!point.empty()){
            int tmp=point.top();
            point.pop();
            cnt++;
            //将度为0的该点以及以该点为弧尾的所有边删除获得一个新图
            for(int i=0;i<edge[tmp].size();i++){
                mark[edge[tmp][i]]--;
                if(mark[edge[tmp][i]]==0){
                    point.push(edge[tmp][i]);
                }
            }
        }
        if(cnt==N) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
