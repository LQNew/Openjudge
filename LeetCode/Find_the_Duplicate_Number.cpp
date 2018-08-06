class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return -1;
        int fast = 0;
        int slow = 0;
        while(true){
        //利用这个数组的分布的规格可以确定利用值作为下标建链表最后一定会进入循环链表中
            slow = nums[slow];//slow对应慢指针，每次移动一步
            fast = nums[nums[fast]]; //fast对应快指针，每次移动两步
            if (fast == slow) { //说明fast指针已经进入循环中，循环中肯定有一个值是重复值，否则不会陷入循环
                fast = 0;
                //此处和Cycle list II不一样的地方是在入口point 之前的一步对应的两个节点一定是相等的，因为这样才能进入循环，所以此处可以找到入口处前一个点的circle值！
                while (fast != slow) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return fast; //指向循环的入口处
            }
        }
    }
};
