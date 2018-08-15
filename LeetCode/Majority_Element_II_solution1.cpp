// 仍然用hash映射的算法去做 orz，不过不是最优的解...
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>hash;
        vector<int> result;
        if(nums.size()==0) return result;
        struct Node{
            int value;
            int freq;
        };
        Node node[nums.size()];
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i]) == hash.end()){
                hash[nums[i]] = cnt;
                node[cnt].value = nums[i];
                node[cnt].freq = 1;
                cnt++;
            }
            else node[hash[nums[i]]].freq++;
        }
        for(int i=0;i<cnt;i++){
            if(node[i].freq > nums.size()/3) result.push_back(node[i].value);
        }
        return result;
    }
};
