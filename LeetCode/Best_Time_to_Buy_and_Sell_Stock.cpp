// 股票的最大利润，momenta面试考察了，我当时就写出了O(n)复杂度的算法，也算是ok了...
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int min1 = prices[0];
        int max1 = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>min1) max1 = max(prices[i]-min1,max1);
            else min1=prices[i];
        }
        return max1;
    }
};
