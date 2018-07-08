//很简单的广搜题，但是竟然WA了很多次，主要是队列没有清空以及初始点没有标记为true，也真的是wa了那么多次，这次要长记性了！！
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N;
int K;
bool mark[200001];
struct Node{
    int x;
    int t;
};
queue<Node>Q;
int go[3][2]={
    1,-1,
    1,1,
    2,0
};
int Bfs(){
    while(!Q.empty()){
        Node now=Q.front();
        Q.pop();
        for(int i=0;i<3;i++){
            int nx=now.x*go[i][0]+go[i][1];
            int nt=now.t;
            if(nx<0||nx>100000) continue;
            if(mark[nx]) continue;
            nt+=1;
            //cout<<nx<<' '<<nt<<endl;
            Node tmp;
            tmp.x=nx;
            tmp.t=nt;
            mark[nx]=true;
            Q.push(tmp);
            if(nx==K) return nt;
        }
    }
}

int main(){
    cin>>N>>K;
    //while(!Q.empty()) Q.pop();
    memset(mark,0,sizeof(mark));
    if(N==K) cout<<0<<endl;
    else{
        Node T;
        T.x=N;
        T.t=0;
        mark[N]=true; //标记为true！很重要！
        Q.push(T);
        int res=Bfs();
        cout<<res<<endl;
    }
    return 0;
}
