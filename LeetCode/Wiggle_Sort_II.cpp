//因为 要求了nums[0]<nums[1]>nums[2]...这种形式而不是 nums[0]<=nums[1]>=nums[2]...这种形式，所以难度上更是大了些，并且 用动归的思路也不能解决绝对大于小于的问题
//利用快排排好序后，从数组的中间（较小值），以及数组的末尾(较大值) 往左扫，下标为偶数是数组中间的往左去，下标为奇数是数组末尾的往左去，这样能保证满足wiggle sort 的形式
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()==0) return;
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(),nums_copy.end());
        int k = (nums.size()+1)/2;
        int j = nums.size();
        for(int i=0; i<nums.size();i++){
            if(i%2 == 0) nums[i] = nums_copy[--k];
            else nums[i] = nums_copy[--j];
        }
    }
};
