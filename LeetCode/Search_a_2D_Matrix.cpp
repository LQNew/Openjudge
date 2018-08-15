class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        // 判断二维数组是不是空的
        if(matrix.size()==0) return found;
        int rows = matrix.size();
        if(matrix[0].size()==0) return found;
        int cols = matrix[0].size();
        // 对于二维数组的查找是从第一行最右侧开始查找，利用了这个二维数组构造的特性去做！
        int row = 0;
        int col = cols - 1;
        while(row<rows && col>=0){
            if(matrix[row][col] == target){
                found = true;
                break;
            }
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return found;
    }
};
