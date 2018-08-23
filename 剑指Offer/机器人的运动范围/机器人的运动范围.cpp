class Solution {
public:
    bool check(int threshold, int rows, int cols, int row, int col, vector<vector<bool>>& visited){
        if(row<0 || row>= rows || col<0 || col>=cols || visited[row][col]) return false;
        int cnt = 0;
        while(row!=0){
           cnt+= row%10;
           row /= 10;
        }
        if(cnt > threshold) return false;
        while(col!=0){
            cnt += col%10;
            col /= 10;
        }
        if(cnt > threshold) return false;
        return true;
    }

    int grid_nums(int threshold, int rows, int cols, int row, int col, vector<vector<bool>>& visited){ //深搜思路~
        int count = 0;
        if(check(threshold, rows, cols, row, col, visited)){
            visited[row][col] = true;
            count =  1 + grid_nums(threshold, rows, cols, row-1, col, visited) \ // 反斜杠表征换行
                       + grid_nums(threshold, rows, cols, row+1, col, visited) \
                       + grid_nums(threshold, rows, cols, row, col+1, visited) \
                       + grid_nums(threshold, rows, cols, row, col-1, visited);
        }
        return count;
    }

    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0 || rows<=0 || cols<=0) return 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols,0));
        int count = grid_nums(threshold, rows, cols, 0, 0, visited);
        return count;
    }
};
