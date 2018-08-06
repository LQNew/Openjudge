class Solution {
public:
    //这道题就是排列组合问题，因为无论怎样，肯定要有m-1步向右以及 n-1步向下，所以相当于 有m-1个黑球，n-1个白球，求所有的排列可能
    //分析可知，这即为 C(m+n-2,n-1)，但是考虑到有大数运算问题，用了double型相乘，不过也会存在这一些精度不够凑的问题，其实也不是很严谨的做法~
    //想严谨做的话，需要用到大数乘法以及除法，这就不大好做了orz~
    int uniquePaths(int m, int n) {
        if(m==1||n==1) return 1;
        int M=m+n-2;
        int N=m-1>n-1?n-1:m-1;
        double ans = 1;
        for(int i=M-N+1,j=1;j<=N;i++,j++){
            ans *= i;
            ans /= j;
        }
        return int(ans);
    }
};
