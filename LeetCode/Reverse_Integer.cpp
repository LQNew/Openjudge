class Solution {
public:
    int reverse(int x) {
        const int MIN = 0X80000000;
        const int MAX = 0X7FFFFFFF;
        long long res = 0; // long long型保证数不会溢出！
        while(x!=0){ // 对于负数，它的除法、取余运算这些和正数都是一样的！
            res = res * 10 + x % 10;
            x /= 10;
        }
        if(res < long(MIN) || res > long(MAX)) return 0;
        else return res;
    }
};
