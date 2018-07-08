//第一次这种在线形式的编程，不是很熟悉，不过此道题 还是很考察逻辑的.
//记住要从矩阵最右角开始查询，如果当前数比目标值大，那么往左边移；
//如果当前数比目标值小，那么往下边移！
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int cols; //矩阵的列数
        int rows; //矩阵的行数
        int row;//矩阵当前的行数
        int col;//矩阵当前的列数
        bool flag=false;
        if(array.size()!=0){
            rows=array.size();
            cols=array[0].size();
            col=cols-1;
            row=0;
            while(col>=0&&row<rows){
                if(array[row][col]==target){
                    flag=true;
                    break;
                }
                else if(array[row][col]>target) col--;
                else row++;
            }
        }
        return flag;
    }
};
