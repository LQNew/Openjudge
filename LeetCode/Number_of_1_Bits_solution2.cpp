// 用到了一个二进制运算的性质：把一个整数减去1后和原来的数进行位与运算，得到的结果相当于把整数的二进制表示中 最右边的1变成0~
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count++;
            n = (n-1) & n;
        }
        return count;
    }
};
