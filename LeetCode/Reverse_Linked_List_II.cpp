/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//对于链表的插入操作等 考查得很全面，算得上一道很好的题目！
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || m==n) return head;
        ListNode* dumpy = new ListNode(-1); //新建一个头结点，方便程序的书写
        dumpy->next = head;
        int cnt=1;
        ListNode* pNode_pre = dumpy;
        while(cnt<m){
            pNode_pre = pNode_pre->next;
            cnt++;
        }
        //用pNode_pre 标识 m节点前的节点
        ListNode* tmpPre = pNode_pre->next; //指向第m节点
        ListNode* tmp = tmpPre->next; // 指向第m+1节点
        ListNode* tmpNext;
        while(cnt<n){
            tmpNext = tmp->next;
            tmp->next = tmpPre;
            tmpPre = tmp;
            tmp = tmpNext;
            cnt++;
        }
        pNode_pre->next->next = tmp;
        pNode_pre->next = tmpPre;
        return dumpy->next;
    }
};
