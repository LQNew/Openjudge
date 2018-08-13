// 求出连续的最大值，也是典型的套路题！ O(n) 复杂度
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int temp_max = 0;
        int max1 = 0;
        int max_minus = 0x80000000; //标识最小值
        for(int i=0;i<nums.size();i++){
            temp_max += nums[i];
            if(temp_max < 0) temp_max = 0; // 如果当前数值小于0，将temp_max 重置为0
            else max1 = max(max1,temp_max); // 如果temp_max 大于0，max1 比对重置
        }
        if(max1!=0) return max1;
        else{ // 如果全为负值，找到最大值
            for(int i=0;i<nums.size();i++) max_minus = max(nums[i],max_minus);
            return max_minus;
            // return *max_element(nums.begin(),nums.end()); //这个函数很快！
        }

    }
};
