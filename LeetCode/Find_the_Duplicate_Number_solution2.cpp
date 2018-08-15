// 一个数组，如果它的数字在1~n 内不重复的话，那么数组排序之后 下标为i的位置上将会出现 i+1的数字
// 重排数组，从头到尾扫描数组，下标为i的数值(用m表示)，是不是等于i+1，不等于的话，将它和第m-1个数字进行比较，如果它和第m-1个数字相等，那么重复数字找到
// 如果不是，把该数值和第m-1个数值交换，把m放到正确的位置上，继续重复这个操作，
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++){
            while((nums[i]-1)!=i){
                if(nums[i]==nums[nums[i]-1]) return nums[i];
                else{
                    swap(nums[i],nums[nums[i]-1]);
                }
            }
        }
        return 0;
    }
};
