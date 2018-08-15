class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int temp = nums[0];
        int count = 1;
        // 如果我们要找的数字出现的次数比其他所有数字出现的次数之和还要多，那么要找的数字肯定是最后一次把count设为1时的数字
        for(int i=1;i<nums.size();i++){
            if(temp == nums[i] ) count++;
            else{
                count--;
                if(count == 0){
                    temp = nums[i];
                    count=1;
                }
            }
        }
        count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==temp) count++;
        }
        if(count>nums.size()/2) return temp;
        else return 0;
    }
};
