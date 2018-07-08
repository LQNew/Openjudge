//本道题题不难，主要在于优先级队列的使用，要用这个思路在！以及关于重载操作符的代码书写要会！
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Node{
    int Q_num;
    int period;
    int time1;
    bool operator<(const Node &b) const{ //操作符重载，重新定义< 号！
       if(time1>b.time1) return 1;
       else if(time1==b.time1)
             if(Q_num>=b.Q_num) return 1;
       return 0;
    }
};
priority_queue<Node>Q; //优先级队列，默认是从小到大排序~
char str2[20];
int a,b;
int K;
Node p;
int main(){
    while(!Q.empty()) Q.pop();
    while(cin>>str2){
        if(strlen(str2)==1&&str2[0]=='#') break;
        cin>>a>>b;
        p.Q_num=a;
        p.period=b;
        p.time1=b;
        Q.push(p);
    }
    cin>>K;
    for(int i=0;i<K;i++){
        Node c=Q.top();
        Q.pop();
        cout<<c.Q_num<<endl;
        c.time1+=c.period;
        Q.push(c);
    }
    return 0;
}
