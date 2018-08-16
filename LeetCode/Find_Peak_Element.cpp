// 对于数组进行遍历找peak值，O(n)算法
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=0) return -1;
        if(nums.size()==1) return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) return i - 1; // 如果nums[i]<nums[i-1]，说明递增序列断了，nums[i-1]>nums[i]，故返回 i-1 下标
        }
        // 如果到数组尾部也没有发现 peak值，但是因为肯定存在peak值，且因为是递增，nums[nums.size()] == 负无穷大，故返回nums.size()-1
        return nums.size()-1;
    }
};
