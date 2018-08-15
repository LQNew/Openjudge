// map映射，开一个节点存储，难度不大，面试的时候面试官对我的回复不是很满意，但我个人而言还是觉得这种做法是可以说得通的
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>hash;
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
            if(node[i].freq > nums.size()/2) return node[i].value;
        }
        return 0;
    }
};
