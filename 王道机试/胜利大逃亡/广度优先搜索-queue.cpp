/*
    Ignatius 被魔王抓走了,有一天魔王出差去了,这可是 Ignatius 逃亡的好机会.魔王住在一个城堡里,城堡是一个 A*B*C 的立方体,可以被表示成 A 个 B*C 的矩
    阵,刚开始 Ignatius 被关在(0,0,0)的位置,离开城堡的门在(A-1,B-1,C-1)的位置,现在知道魔王将在 T 分钟后回到城堡,Ignatius 每分钟能从一个坐标走到相邻的六个
    坐标中的其中一个.现在给你城堡的地图,请你计算出 Ignatius 能否在魔王回来前离开城堡(只要走到出口就算离开城堡,如果走到出口的时候魔王刚好回来也算逃
    亡成功),如果可以请输出需要多少分钟才能离开,如果不能则输出-1。
*/
//分析：可以构造搜索树的思路去处理深搜问题，用mark标记，用队列存储当前节点状态，不断地遍历，利用了遍历树节点时最先到达的时间是最优的，所以可以每次到达时可以mark下
//这种是典型的广搜题，难度一般，很有套路~！
#include<iostream>
#include<queue>
using namespace std;
bool mark[50][50][50];
int maze[50][50][50];
int K,A,B,C,T;
int ret;
struct Node{
    int x;
    int y;
    int z;
    int t;
};
queue<Node> Q;
int go[][3]={
    0,0,1,
    0,0,-1,
    0,1,0,
    0,-1,0,
    1,0,0,
    -1,0,0
};
int BFS(int a,int b,int c){
    while(!Q.empty()){
        Node new_1=Q.front(); //此处队列处理搜索树的遍历思路很好，是模板程序，值得多加理解记忆！！
        Q.pop();
        for(int i=0;i<6;i++){
            int nx=new_1.x+go[i][0];
            int ny=new_1.y+go[i][1];
            int nz=new_1.z+go[i][2];
            if(nx<0||nx>=A||ny<0||ny>=B||nz<0||nz>=C) continue;
            if(maze[nx][ny][nz]==1) continue;
            if(mark[nx][ny][nz]==true) continue;
            Node tmp;
            tmp.x=nx;
            tmp.y=ny;
            tmp.z=nz;
            tmp.t=new_1.t+1;
            Q.push(tmp);
            mark[nx][ny][nz]=true;
            if(nx==A-1&&ny==B-1&&nz==C-1) return tmp.t;
        }
    }
}
int main(){
    while(cin>>K){
        for(int cnt=0;cnt<K;cnt++){
            cin>>A>>B>>C>>T;
            for(int i=0;i<A;i++){
                for(int j=0;j<B;j++){
                    for(int k=0;k<C;k++){
                        cin>>maze[i][j][k];
                        mark[i][j][k]=false;
                    }
                }
            }
        }
        while(!Q.empty()) Q.pop();
        Node tmp;
        tmp.t=tmp.x=tmp.y=tmp.z=0;
        mark[0][0][0]=true;
        Q.push(tmp);
        ret=BFS(A,B,C);
        //cout<<ret<<" "<<T<<endl;
        if(ret<=T) cout<<ret<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
