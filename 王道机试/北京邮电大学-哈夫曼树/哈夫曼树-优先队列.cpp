/*
    哈夫曼树，第一行输入一个数 n，表示叶结点的个数。需要用这些叶结点生成哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即 weight，题目需要输出
    所有结点的值与权值的乘积之和。
*/
//分析：节点的值与权值的乘积，仔细分析可以发现就是所有的非叶节点上的权值之和
//关于构造哈夫曼树此处用了优先级队列，小顶堆方式构造，难度较为简单，可以多多体会！！
//对于小顶堆，就是每次进入优先队列，较小的值置于队列前部，按照堆排序方式构造优先队列~堆顶元素为最小值
//其实本道题仔细一思考也可以采用快速排序方式，但是快速排序可能书写起来没有那么方便~
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> Q; //小顶堆的构造方式！ 默认是大顶堆，也就是 priority_queue<int>就好
int n;
int weight;
int main(){
    while(cin>>n){
        while(!Q.empty()) Q.pop();
        for(int i=0;i<n;i++){
            cin>>weight;
            Q.push(weight);
        }
        int ans=0;
        while(Q.size()>1){
            int a=Q.top();
            Q.pop();
            int b=Q.top();
            Q.pop();
            ans+=(a+b);
            Q.push(a+b);
        }
        cout<<ans<<endl;
    }
    return 0;
}
