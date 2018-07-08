/*
    编程实现Huffman算法并计算最小外部路径长度总和。
*/
//计算Huffman树的最短外部路径，自己画图可以理解其实就是计算非叶节点之外所有结点的权值之和
//此处利用了优先级队列STL库操作，难度较易！
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
