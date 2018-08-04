//我用广搜的思路去处理此种问题，从某种程度上说是我自己的习惯，对于这种连通域求解问题，我习惯于广搜处理~
#include<queue>
struct Node{
    int x;
    int y;
};
queue<Node>Q;
int rows;
int cols;
bool judge[1000][1000];
int go[4][2]={
    1,0,
    0,1,
    -1,0,
    0,-1
};
void Bfs(vector<vector<char>>& grid){
    while(!Q.empty()){
        Node now=Q.front();
        Q.pop();
        int nx;
        int ny;
        for(int i=0;i<4;i++){
            nx=now.x+go[i][0];
            ny=now.y+go[i][1];
            if(nx<0||nx>=rows||ny>=cols||ny<0) continue;
            if(grid[nx][ny]=='0'||judge[nx][ny]) continue;
            Node tmp;
            tmp.x=nx;
            tmp.y=ny;
            judge[nx][ny]=true;
            Q.push(tmp);
        }
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        if(grid[0].size()==0) return 0;
        rows=grid.size();
        cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++) judge[i][j]=false;
        }
        int cnt=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(judge[i][j]||grid[i][j]=='0') continue;
                judge[i][j]=true;
                cnt++;
                Node tmp;
                tmp.x=i;
                tmp.y=j;
                while(!Q.empty()) Q.pop();
                Q.push(tmp);
                Bfs(grid);
            }
        }
        return cnt;
    }
};
