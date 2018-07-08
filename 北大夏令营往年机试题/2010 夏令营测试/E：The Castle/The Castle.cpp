//用广搜处理，最大连通子图，题目稍微有些繁琐写起来...
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct Map1{
    bool east;
    bool west;
    bool north;
    bool south;
};
struct Node{
    int x;
    int y;
};
Map1 map1[51][51];
bool flag[51][51];
int a[4];
int m,n;
int a1;
int ans;
int go[4][2]={
    0,1,
    1,0,
    -1,0,
    0,-1
};
queue<Node>Q;

void decomposition(int x){
    int cnt=0;
    while(x){
        a[cnt]=x%2;
        x/=2;
        cnt++;
    }
}

void BFS(){
    while(!Q.empty()){
        Node new1=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int dx=new1.x+go[i][0];
            int dy=new1.y+go[i][1];
            if(dx<=0||dx>m||dy<=0||dy>n) continue;
            if(flag[dx][dy]) continue;
            if(map1[new1.x][new1.y].west&&go[i][1]==-1) continue;
            if(map1[new1.x][new1.y].east&&go[i][1]==1) continue;
            if(map1[new1.x][new1.y].north&&go[i][0]==-1) continue;
            if(map1[new1.x][new1.y].south&&go[i][0]==1) continue;
            Node tmp;
            tmp.x=dx;
            tmp.y=dy;
            ans++;
            flag[dx][dy]=true;
            Q.push(tmp);
        }
    }
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a1;
            memset(a,0,sizeof(a));
            decomposition(a1);
            bool west=false;
            bool east=false;
            bool north=false;
            bool south=false;
            if(a[0]==1) west=true;
            if(a[1]==1) north=true;
            if(a[2]==1) east=true;
            if(a[3]==1) south=true;
            map1[i][j].east=east;
            map1[i][j].west=west;
            map1[i][j].north=north;
            map1[i][j].south=south;
            flag[i][j]=false;
        }
    }
    int cnt=0;
    int max1=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(!flag[i][j]){
                while(!Q.empty()) Q.pop();
                cnt++;
                Node tmp;
                tmp.x=i;
                tmp.y=j;
                flag[i][j]=true;
                Q.push(tmp);
                ans=1;
                BFS();
                max1=max(max1,ans);
            }
        }
    }
    cout<<cnt<<endl;
    cout<<max1<<endl;
    return 0;
}
