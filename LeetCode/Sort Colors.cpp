//completely quick sort without library's qsort function
int Partion(vector<int>& nums, int first, int end){
    int i=first;
    int j=end;
    int pivot=nums[i];
    while(i<j){
        while((i<j)&&(nums[j]>=pivot))
            j--;
        nums[i]=nums[j];
        while((i<j)&&(nums[i]<=pivot))
            i++;
        nums[j]=nums[i];
    }
    nums[i]=pivot;
    return i;
}
void Qsort(vector<int>& nums, int i, int j){
    if(i<j){
        int pivotloc=Partion(nums, i, j);
        Qsort(nums, i, pivotloc-1);
        Qsort(nums, pivotloc+1, j);
    }
}
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        Qsort(nums, i, j);
    }
};
