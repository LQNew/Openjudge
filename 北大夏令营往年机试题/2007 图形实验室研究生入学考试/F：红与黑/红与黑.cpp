//深搜做得，写得不是很熟练orz
#include<iostream>
using namespace std;
char map1[21][21];
int W,H;
int x0,y0;
bool mark[21][21];
int cnt;
int go[4][2]={
    -1,0,
    1,0,
    0,-1,
    0,1
};
void Dfs(int x,int y){
    for(int i=0;i<4;i++){
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(nx<0||nx>=H||ny<0||ny>=W) continue;
        if(map1[nx][ny]!='.'||mark[nx][ny]==true) continue;
        mark[nx][ny]=true;
        Dfs(nx,ny);
    }
}
int main(){
    while(cin>>W>>H){
        if(W==0&&H==0) break;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                mark[i][j]=false;
                cin>>map1[i][j];
                if(map1[i][j]=='@'){
                    x0=i;
                    y0=j;
                }
            }
        }
        cnt=0;
        mark[x0][y0]=true;
        Dfs(x0,y0);
        for(int i=0;i<H;i++){ //遍历深搜结果，获取黑板砖数目
            for(int j=0;j<W;j++){
                if(mark[i][j]) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
