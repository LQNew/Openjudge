//常规解法会TL，此处改用快速幂算法
//本道题有点意思，会发现int型它小于0如果最小值翻转后是为0！于是需要考虑将数字表示的形式转换为别的可以表示更大位数的形式，如unsigned、此处我增设long型去表示更大位数
class Solution {
public:
    double myPow(double x, int n) {
        long n1 = n;
        long n2;
        if(n < 0) n2 = -n1;
        else n2 = n1;
        double a = 1.0;
        while(n2 != 0){
            if(n2 % 2 == 1) a *= x;
            n2 /= 2;
            x *= x;
        }
        if(n < 0) return 1.0 / a;
        else return a;
    }
};
