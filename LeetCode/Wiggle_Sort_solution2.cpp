class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        // write your code here
        if(nums.size()==0) return;
        for(int i=1;i<nums.size();i++){
            if(i%2==1 && nums[i]<nums[i-1]) swap(nums[i], nums[i-1]);
            else if(i%2==0 && nums[i]>nums[i-1]) swap(nums[i], nums[i-1]);
        }
    }
};
