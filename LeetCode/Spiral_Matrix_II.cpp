//在spiral_matrix的基础上改进下，但是应该不是最优算法orz...
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i=1;
        vector<vector<int>> matrix(n,vector<int>(n));
        int l,r,d,u;
        l=0;r=n-1;d=n-1;u=0;
        while(true){
            //right
            for(int col=l;col<=r;col++){
                matrix[u][col]=i;
                i++;
            }
            u++;
            if(u>d) break;
            //down
            for(int row=u;row<=d;row++){
                matrix[row][r]=i;
                i++;
            }
            r--;
            if(r<l) break;
            //left
            for(int col=r;col>=l;col--){
                matrix[d][col]=i;
                i++;
            }
            d--;
            if(d<u) break;
            //up
            for(int row=d;row>=u;row--){
                matrix[row][l]=i;
                i++;
            }
            l++;
            if(l>r) break;
        }
        return matrix;
    }
};
