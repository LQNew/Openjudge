//含有阻碍的路径数目求解，dp算法的应用，难度不大，但是还是需要多加理解~
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        int dp[m][n];
        int f=1;
        for(int i=0;i<n;i++){ //因为只能向右或向下走，所以当向下走的路上一旦有一个阻碍，那么接下来的都没法走了
            if(obstacleGrid[0][i]==1) f=0;
            dp[0][i]=f;
        }
        f=1;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1) f=0; //因为只能向右或向下走，所以当向右走的路上一旦有一个阻碍，那么接下来的都没法走了
            dp[i][0]=f;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0; //遇到阻碍时，该点不可前行，前面的积淀全部清为0
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
};
