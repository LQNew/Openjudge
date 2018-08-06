// 最长递增子序列的解法，就是求出当前以当前下标的数为结尾的可获取的最大子序列长度
// 最长递增子序列考研中 模板解法~
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size());
        for(int i=0;i<nums.size();i++){ //迭代过程~
            int max1=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) max1=max(dp[j]+1,max1);
            }
            dp[i]=max1;
        }
        int ans=1;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
