/*
    有一个 N*M 的迷宫，包括起点 S，终点 D，墙 X，和地面，0秒时主人公从 S 出发，每秒能走到四个与其相邻的位置中的一个，且每个位置被
    行走之后都不能再次走入，问是否存在这样一条路径使主人公在 T 秒时刚好走到 D。
*/
//分析；典型的深搜题目，就是从一个节点一站到底，只要达到要求即返回，要加上返回条件才能保证深搜过程顺利进行！！
//此处有则细节：主人公每走一步时，其所在位置坐标中，只有一个坐标分量发生增一或者减一的改变，那么两个坐标分量和的奇偶性将发生变化。这样，
//当主人公走过奇数步时，其所在位置坐标和的奇偶性必与原始位置不同；而走过偶数步时，其坐标和的奇偶性与起点保持不变。若起点的坐标和的奇偶性和终点
//的坐标和不同，但是需要经过偶数秒使其刚好达到，显然的这是不可能的，于是我们直接判定这种情况下，整棵解答树中都不可能存在我们所需的状态，跳过搜
//索部分，直接输出 NO。
#include<iostream>
using namespace std;
int M,N,T;
int ex,ey;
int bx,by;
bool success;
char map1[7][7];
bool mark[7][7];
int go[][2]={
    -1,0,
    1,0,
    0,-1,
    0,1
};
void Dfs(int x,int y,int t){ //深搜，一站到底！要理解其中递归以及如何返回的细节！
    for(int i=0;i<4;i++){
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(nx<=0||nx>M||ny<=0||ny>N) continue;
        if(mark[nx][ny]) continue;
        if(map1[nx][ny]=='X') continue;
        if(map1[nx][ny]=='D'){
            int time=t+1;
            if(time==T){
                cout<<"YES"<<endl;
                success=true;
            }
            else continue;//说明此时遍历此点并不合适，于是遍历其他点
        }
        else{
            mark[nx][ny]=true;
            Dfs(nx,ny,t+1);
            mark[nx][ny]=false;
        }
        if(success==true) return;
    }
    return;
}
int main(){
    while(cin>>M>>N>>T){
        success=false;
        if(M==0&&N==0&&T==0) break;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                cin>>map1[i][j];
                mark[i][j]=false;
            }
        }
        for(int i=1;i<=M;i++){ //找到终点坐标
            for(int j=1;j<=N;j++){
                if(map1[i][j]=='D'){
                    ex=i;
                    ey=j;
                }
            }
        }
        for(int i=1;i<=M;i++){ //找到起点坐标
            for(int j=1;j<=N;j++){
                if(map1[i][j]=='S'){
                    bx=i;
                    by=j;
                }
            }
        }
        if((bx+by)%2==(((ex+ey)%2)+T%2)%2){ //检验起点和终点的奇偶性与时间的关系！！
            Dfs(bx,by,0);
            if(!success) cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
