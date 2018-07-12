//广搜水题，没有找到测试平台，代码正确性不能保证，但是样例测试都是可以跑通的
#include<iostream>
#include<queue>
using namespace std;
const int INF=0x7fffffff;
int K;
int m,T;
char map1[11][11];
bool judge[11][11];
int go[4][2]={
    0,1,
    1,0,
    0,-1,
    -1,0
};
struct Node{
    int x;
    int y;
    int step;
};
queue<Node>Q;
int initial_x,initial_y;

int Bfs(){
    while(!Q.empty()){
        Node now=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int nx=now.x+go[i][0];
            int ny=now.y+go[i][1];
            if(nx<=0||nx>m||ny<=0||ny>m) continue;
            if(judge[nx][ny]||map1[nx][ny]=='#') continue;
            int steps=now.step+1;
            if(map1[nx][ny]=='E') return steps;
            Node tmp;
            tmp.step=steps;
            tmp.x=nx;
            tmp.y=ny;
            judge[nx][ny]=true;
            Q.push(tmp);
        }
    }
    return INF;
}
int main(){
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>m>>T;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cin>>map1[i][j];
                judge[i][j]=false;
                if(map1[i][j]=='S'){
                    initial_x=i;
                    initial_y=j;
                }
            }
        }
        Node tmp;
        tmp.x=initial_x;
        tmp.y=initial_y;
        tmp.step=0;
        judge[tmp.x][tmp.y]=true;
        while(!Q.empty()) Q.pop();
        Q.push(tmp);
        int steps=Bfs();
        if(steps<=T) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
