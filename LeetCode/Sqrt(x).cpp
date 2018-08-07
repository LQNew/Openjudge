class Solution {
public:
    //二分查找，因为x的平方根肯定小于x/2，所以平方根就在 [1,x/2]之间
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int high = x/2 + 1;
        int low = 1;
        int mid;
        while(high>=low){
            mid = (high+low)/2;
            if(long(mid)*(long)mid==x) return mid;
            else if(long(mid)*long(mid)>x) high = mid-1;
            else low = mid+1;
        }
        return high;
    }
};
