/*
    给出一个图的结构，输出其拓扑排序序列，要求在同等条件下，编号小的顶点在前。
*/
//拓扑排序，就是每次找到当前入度为0的节点将它弹出，然后连带着它所指向的边也都删除，然后再找下一个入度为0的节点
//因为此处是要求每次都是编号小的顶点弹出，于是构造一个优先队列，每次队头存放的都是最小值
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int mark[101]; //用于记录每个节点的入度值
int v1,v2;
vector<int>edge[101]; //记录临接链表
priority_queue<int,vector<int>,greater<int>> Q; //优先队列构造，此处是申明小顶堆，即队头为最小值，注意优先队列默认是大顶堆，
int v,a;
int main(){
    while(cin>>v>>a){
        for(int i=1;i<=v;i++){
            edge[i].clear();
            mark[i]=0;
        }
        for(int i=0;i<a;i++){
            cin>>v1>>v2;
            mark[v2]++;
            edge[v1].push_back(v2);
        }
        while(!Q.empty()) Q.pop();
        for(int i=1;i<=v;i++){ //找到入度为0的节点压入
            if(mark[i]==0) Q.push(i);
        }
        while(!Q.empty()){
            int tmp=Q.top();
            Q.pop();
            cout<<'v'<<tmp<<' ';
            for(int i=0;i<edge[tmp].size();i++){
                mark[edge[tmp][i]]--;
                if(mark[edge[tmp][i]]==0){ //找出是否有新增的入度为0的节点
                    Q.push(edge[tmp][i]);
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
