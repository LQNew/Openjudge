//旋转数组题，逻辑问题，难度不是很大~
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>spiral(m*n);
        int u, r, l, d, k;
        u=0;r=n-1;l=0;d=m-1;k=0;
        while(true){
            //right
            for(int col=l;col<=r;col++) spiral[k++]=matrix[u][col];
            u++;
            if(u>d) break;
            //down
            for(int row=u;row<=d;row++) spiral[k++] = matrix[row][r];
            r--;
            if(r<l) break;
            //left
            for(int col=r;col>=l;col--) spiral[k++] = matrix[d][col];
            d--;
            if(d<u) break;
            //up
            for(int row=d;row>=u;row--) spiral[k++] = matrix[row][l];
            l++;
            if(l>r) break;
        }
        return spiral;
    }
};
