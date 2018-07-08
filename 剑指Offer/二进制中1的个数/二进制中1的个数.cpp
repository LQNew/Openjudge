//求二进制中1的个数，这个解法思路很溜！！
class Solution{
public:
    int NumberOf1(int n){
        int count=0;
        unsigned int flag = 1; //利用了unsigned int 的纯正数性质
        while(flag){ //当flag右移32位后，它会变为0，这是刚好整个int型变量也过了一遍
            if(n&flag) count++; //只和一个只有一位为1，其余位全为0的数相与，只会有要么为0，要么非0的结果
            flag=flag<<1;
        }
        return count;
    }
};
