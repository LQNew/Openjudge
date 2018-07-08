#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Node{
    int Q_num;
    int period;
    int time1;
    bool operator<(const Node &b) const{
       if(time1>b.time1) return 1;
       else if(time1==b.time1)
             if(Q_num>=b.Q_num) return 1;
       return 0;
    }
};
priority_queue<Node>Q;
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
