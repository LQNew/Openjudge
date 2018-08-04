 /*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //slow pointer moves 1 step, and fast pointer moves 2 steps, if there exists a circle, they'll meet!
        if(head==NULL||head->next==NULL||head->next->next==NULL) return false;
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while(slow!=fast){
            if(slow->next==NULL) return false;
            slow=slow->next;
            if(fast->next==NULL||fast->next->next==NULL) return false;
            fast=fast->next->next;
        }
        return true;
    }
};
