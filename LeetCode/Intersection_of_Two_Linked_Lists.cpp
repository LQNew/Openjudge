/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 找到两个链表的公共节点，也是有一定的技巧性的题！
class Solution {
public:
    unsigned int Get_length(ListNode *a){ // 计算链表的值
        unsigned int cnt = 0;
        while(a!=NULL){
            cnt++;
            a = a->next;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 获取长链表和短链表，以及长链表和短链表的长度差值
        unsigned int headA_length = Get_length(headA);
        unsigned int headB_length = Get_length(headB);
        unsigned int minus = headA_length - headB_length;
        ListNode *long_list = headA;
        ListNode *short_list = headB;
        if(headA_length < headB_length){
            minus = headB_length - headA_length;
            long_list = headB;
            short_list = headA;
        }

        for(int i=0;i<minus;i++) long_list = long_list->next; // 长链表先走上差值个步数
        while(long_list!=NULL && (long_list!=short_list)){ //之后开始比对后面的链表是否一致~
            long_list = long_list->next;
            short_list = short_list->next;
        }
        ListNode *common = long_list;
        return common;
    }
};
