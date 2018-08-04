//题目很长，读起来甚至不知所云，但本质上就是一个求连通域个数的问题，不过题目中显示有.的连通域，又有X的连体域，算是双重连通域问题吧！
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
char map1[55][55];
bool judge[50][50];
struct Node{
    int x;
    int y;
};
int go[4][2]={
    1,0,
    0,1,
    -1,0,
    0,-1
};
queue<Node>Q;
queue<Node>Q1;
int w,h;
int cnt=0;
int num[1000];

void Bfs1(){
    while(!Q1.empty()){
        Node new1=Q1.front();
        Q1.pop();
        for(int i=0;i<4;i++){
            int nx=new1.x+go[i][0];
            int ny=new1.y+go[i][1];
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(map1[nx][ny]!='X'||judge[nx][ny]) continue;
            Node tmp;
            tmp.x=nx;
            tmp.y=ny;
            judge[nx][ny]=true;
            Q1.push(tmp);
            Q.push(tmp);
        }
    }
}

int Bfs(){
    int cnt1=0;
    while(!Q.empty()){
        Node new1=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int nx=new1.x+go[i][0];
            int ny=new1.y+go[i][1];
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(map1[nx][ny]=='.'||judge[nx][ny]) continue;
            if(map1[nx][ny]=='X'){
                Node tmp;
                tmp.x=nx;
                tmp.y=ny;
                judge[nx][ny]=true;
                while(!Q1.empty()) Q1.pop();
                Q.push(tmp);
                Q1.push(tmp);
                Bfs1();
                cnt1++;

            }
            else{
                Node tmp;
                tmp.x=nx;
                tmp.y=ny;
                judge[nx][ny]=true;
                Q.push(tmp);
            }
        }
    }
    return cnt1;
}

int compare(const void* a,const void* b){
    return *(int*)a- *(int*)b;
}
int main(){
    while(cin>>w>>h){
        if(w==0&&h==0) break;
        cnt++;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map1[i][j];
                judge[i][j]=false;
            }
        }
        int num1=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map1[i][j]=='.'||judge[i][j]) continue;
                Node tmp;
                tmp.x=i;
                tmp.y=j;
                judge[i][j]=true;
                while(!Q.empty()) Q.pop();
                Q.push(tmp);
                int step=Bfs();
                num[num1]=step;
                num1++;
            }
        }
        qsort(num,num1,sizeof(int),compare);
        cout<<"Throw "<<cnt<<endl;
        for(int i=0;i<num1-1;i++)
            cout<<num[i]<<' ';
        cout<<num[num1-1]<<endl;
        cout<<endl;
    }
    return 0;
}
