/*
    已知一张地图（以二维矩阵的形式表示）以及佐助和鸣人的位置。地图上的每个位置都可以走到，只不过有些位置上有大蛇丸的手下，
    需要先打败大蛇丸的手下才能到这些位置。鸣人有一定数量的查克拉，每一个单位的查克拉可以打败一个大蛇丸的手下。
    假设鸣人可以往上下左右四个方向移动，每移动一个距离需要花费1个单位时间，打败大蛇丸的手下不需要时间。
    如果鸣人查克拉消耗完了，则只可以走到没有大蛇丸手下的位置，不可以再移动到有大蛇丸手下的位置。佐助在此期间不移动，大蛇丸的手下也不移动。
    要求求出鸣人追上佐助的最短时间
*/
//本道题乍一看就是二维的广搜问题，但是 一开始按照此思路WA了，后来想到查卡拉也属于一个变量，因为在地图不同点处可能查克拉不同就意味着不同的走向，
//于是增设一维表征查克拉变量
#include<iostream>
#include<queue>
using namespace std;
int M,N,T;
int x0,y0;//初始时鸣人的坐标
char c;//存储输入的地图的字符值
char Map[200][200][11]; //增设查克拉维度
bool mark[200][200][11];
struct Node{
    int x; //节点横坐标
    int y; //节点纵坐标
    int t; //节点的查克拉
    int res;//移动的步数
};
queue<Node>Q;
int go[4][2]={ //表征四个方向的移动
    -1,0,
    0,1,
    0,-1,
    1,0
};

int Bfs(){
    while(!Q.empty()){
        Node now=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int x1=go[i][0]+now.x;
            int y1=go[i][1]+now.y;
            int t1=now.t;
            if(x1<0||x1>=M||y1<0||y1>=N) continue;
            if(mark[x1][y1][t1]) continue;
            if(Map[x1][y1][t1]=='#'){
                if(t1>0) t1-=1;
                else continue;
            }
            mark[x1][y1][t1]=true;
            Node tmp;
            tmp.x=x1;
            tmp.y=y1;
            tmp.t=t1;
            tmp.res=now.res+1; //步数+1
            //cout<<tmp.res<<' '<<Map[x1][y1]<<endl;
            Q.push(tmp);
            if(Map[x1][y1][t1]=='+') return tmp.res; //在任意的查克拉维度上，只要检测出地图中该点已经到达佐助，那么查询完毕
        }
    }
    return -1;
}

int main(){
    while(cin>>M>>N>>T){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cin>>c;
                for(int k=0;k<=T;k++) Map[i][j][k]=c; //各个维度初始化
                if(c=='@'){
                    x0=i;
                    y0=j;
                }
                for(int k=0;k<=T;k++) mark[i][j][k]=false;
            }
        }
        mark[x0][y0][T]=true;
        Node tmp;
        tmp.x=x0;
        tmp.y=y0;
        tmp.t=T;
        tmp.res=0;
        while(!Q.empty()) Q.pop();
        Q.push(tmp);
        int res=Bfs();
        cout<<res<<endl;
    }
    return 0;
}
