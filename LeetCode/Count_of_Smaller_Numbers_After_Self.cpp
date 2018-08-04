//在归并排序的基础上额外加一个标识数组去标识下标，比对数值计数，蛮容易的思路~
//不过比较耗时也是醉了...我觉得可能是我不断新开数组，清空内存导致了这个问题...
class Solution {
public:
    vector<int> count;
    vector<int> flag;
    void Merge_pass(vector<int>& A, vector<int>& nums, vector<int>& L, int left_count, vector<int>& R, int right_count){
        int i,j,k;
        i = 0; j = 0; k = 0;
        while(i<left_count && j<right_count){
            if(nums[L[i]]<=nums[R[j]]) A[k++] = L[i++];
            else{
                for(int z=i;z<left_count;z++) count[L[z]]++;
                A[k++] = R[j++];
            }
        }
        while(i<left_count) A[k++]=L[i++];
        while(j<right_count) A[k++]=R[j++];
    }

    void Merge_sort(vector<int>& A, vector<int>& nums, int cnt1){
        int mid = cnt1/2;
        if(mid==0) return;
        vector<int> L(mid);
        vector<int> R(cnt1-mid);
        for(int i=0;i<mid;i++) L[i] = A[i];
        for(int j=mid;j<cnt1;j++) R[j-mid] = A[j];
        Merge_sort(L,nums,mid);
        Merge_sort(R,nums,cnt1-mid);
        Merge_pass(A,nums,L,mid,R,cnt1-mid);
        L.clear();
        R.clear();
    }

    vector<int> countSmaller(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            flag.push_back(i);
            count.push_back(0);
        }
        Merge_sort(flag,nums,nums.size());
        return count;
    }
};
