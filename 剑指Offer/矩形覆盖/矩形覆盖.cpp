// 矩形覆盖题，实则是一道 斐波那契数列问题，难度不是那么大，主要是自己归纳出这个递推关系！
class Solution {
public:
    int rectCover(int number) {
        if( number <= 0 ) return 0;
        if( number == 1 ) return 1;
        int a = 1;
        int b = 1;
        int c;
        for(int i=2;i<=number;i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
