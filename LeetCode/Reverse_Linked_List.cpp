//主要是用到了常规的反转链表操作~
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pReversedHead;
        ListNode* pNode = head; // 保存当前结点
        ListNode* pPrev = NULL; // 保存前一节点
        ListNode* pNext; // 记录后一节点
        while(pNode!=NULL){
            pNext=pNode->next;
            if(pNext==NULL) pReversedHead = pNode;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReversedHead;
    }
};
