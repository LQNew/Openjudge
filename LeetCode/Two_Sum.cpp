#include <map>
//最核心的思路就是采用map映射，此外本题的思路也很好，就是每次记录之前已经查找过的值，并将它们用map表映射，将值与下标之间做一个映射，查询
//利用到了map映射查询是用红黑树的方法，本身就是速度很快的查询
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	    map<int, int> hash;
	    vector<int> result;
	    for (int i = 0; i < nums.size(); i++) {
		    int numberToFind = target - nums[i];
		    if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
		    }
            hash[nums[i]] = i; //如果该值不在表中，将其引入映射之中
	    }
	    return result;
    }
};
