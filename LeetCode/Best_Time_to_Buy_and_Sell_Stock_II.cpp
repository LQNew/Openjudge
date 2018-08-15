//momenta一面原题，看代码好像很容易，但本道题其实没有想象中那么水，它背后的逻辑是很深刻的！
//可以自己画画线段图去思索一下！
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int res = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) res += (prices[i] - prices[i-1]);
        }
        return res;
    }
};
