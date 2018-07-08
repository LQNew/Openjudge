//广搜问题，难度较小，简单的计数
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int W,H;
char map1[21][21];
bool passed[21][21];
int cnt;
int go[4][2]={
    -1,0,
    1,0,
    0,-1,
    0,1
};
struct Node{
    int x;
    int y;
};
queue<Node>Q;
int Bfs(){
    while(!Q.empty()){
        Node now=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int dx=now.x+go[i][0];
            int dy=now.y+go[i][1];
            if(dx<0||dy<0||dx>=H||dy>=W) continue;
            if(passed[dx][dy]||map1[dx][dy]!='.') continue;
            cnt++;
            Node tmp;
            tmp.x=dx;
            tmp.y=dy;
            passed[dx][dy]=true;
            Q.push(tmp);
        }
    }
    return cnt;
}
int main(){
    int x0,y0;
    while(cin>>W>>H){
        if(W==0&&H==0) break;
        cnt=0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin>>map1[i][j];
                if(map1[i][j]=='@'){
                    x0=i;
                    y0=j;
                }
            }
        }
        memset(passed,0,sizeof(passed));
        Node tmp;
        tmp.x=x0;
        tmp.y=y0;
        while(!Q.empty()) Q.pop();
        Q.push(tmp);
        cnt++;
        passed[x0][y0]=true;
        cout<<Bfs()<<endl;
    }
    return 0;
}
