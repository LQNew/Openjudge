class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //从前往后扫，以及从后往前扫，求乘积，空位置，可以自己纸上先推演下规律！
        //后有思维性的一道题，不错！
        vector<int> res;
        int pre=1;
        for(int i=0;i<nums.size();i++){
            res.push_back(pre);
            pre*=nums[i];
        }
        int post=1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i]=res[i]*post;
            post*=nums[i];
        }
        return res;
    }
};
