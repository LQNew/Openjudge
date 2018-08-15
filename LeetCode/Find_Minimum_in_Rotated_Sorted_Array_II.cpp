// 旋转数组的求最小数字题目中最难的形式的题型了，主要是对于duplicate numbers，如果index1,index2,middle 三个值都相等的话，那么再移动肯定会陷入死循环，这时就需要顺序查找一下了orz
class Solution {
public:
    int ordered_search(vector<int>& nums, int index1, int index2){ // 顺序查找
        int result = nums[index1];
        for(int i = index1 + 1 ;i <= index2; i++){
            if(nums[i]<result) result = nums[i];
        }
        return result;
    }

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
            if(nums[middle]==nums[index1] && nums[index1]==nums[index2]) return ordered_search(nums,index1,index2); // 对于duplicate number的处理方式！
            if(nums[middle] >= nums[index1]) index1 = middle;
            // 若果中间下标对应的数值 大于index1对应的数值，说明middle下标此时还在递增序列中，index 指向数组中间
            else index2 = middle; //如果middle指针 对应的数值 小于index1对应的数值，说行middle在递减序列中，index2 指向middle
        }
        return nums[middle];
    }
};
