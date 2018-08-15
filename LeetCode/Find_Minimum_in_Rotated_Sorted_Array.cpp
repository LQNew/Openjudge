// 找出旋转数组中的最小值，面试常考题型！
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<=0) return -1;
        if(nums.size()==1) return nums[0];
        int index1 = 0;
        int index2 = nums.size() - 1;
        int middle = index1; // 为了应付倘若是递增序列的初始化处理方式
        // 二分查找的思路
        while(nums[index1]>=nums[index2]){
            if(index2 - index1 == 1) return nums[index2];
            middle = (index1 + index2) / 2;
            if(nums[middle] >= nums[index1]) index1 = middle;
            // 若果中间下标对应的数值 大于index1对应的数值，说明middle下标此时还在递增序列中，index 指向数组中间
            else index2 = middle; //如果middle指针 对应的数值 小于index1对应的数值，说行middle在递减序列中，index2 指向middle
        }
        return nums[middle];

    }
};
