//O(n)的解法
//没有优化到时间复杂度为O(1)，空间复杂度优化为了O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size==0) return; //思路的严谨性
        k = k%size;
        if(k==0) return; //思路的严谨性
        vector<int> res;
        for(int j=size-k;j<size;j++) res.push_back(nums[j]);
        for(int j=size-1;j>=k;j--) nums[j]=nums[j-k];
        //memcpy(&nums[0],&res[0],sizeof(int)*k); //拷贝赋值操作
        for(int i=0;i<k;i++) nums[i]=res[i]; //直接赋值
    }
};
