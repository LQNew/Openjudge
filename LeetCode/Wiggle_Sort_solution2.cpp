//i下标为偶数值时 肯定要<=nums[i-1]；i下标为奇数值时，肯定要>=nums[i-1]
//从数组的起始部分按照此思路更迭，不满足条件得变交换数值，直至数组尾部，此时便得到了wiggle_sort array
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
