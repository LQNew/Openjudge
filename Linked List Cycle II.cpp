/*
    Let us give the distance a variable name, x, y and z.
    [head] ---x---> [Cycle_Start] ---y---> [MeetPoint](fast/slow runner) ---z---> [Cycle_Start]
    At this moment, fast and slow runner are both at [MeetPoint].
    The problem is equal to "How many steps should slow runner run to [Cycle_Start]?".
    In other words, "How many steps is z distance?"
    The distance run by slow runner = x + y
    The distance run by fast runner = x + y + z + y
    Since fast runner is two times faster than slow runner.
    fast = 2 * ( slow )
    x + y + z + y = 2 * ( x + y )
    x + 2y + z = 2x + 2y
    z = x
    It means slow runner should run z steps to [Cycle_Start] point from [MeetPoint].
    And z distance is the same as x distance.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return NULL;
        ListNode *slow=head->next;
        ListNode *fast=head->next->next;
        while(slow!=fast){ //if slow pointer meets fast pointer, it means there exists a circle
            if(slow->next==NULL) return NULL;
            slow=slow->next;
            if(fast->next==NULL||fast->next->next==NULL) return NULL;
            fast=fast->next->next;
        }
        fast=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
