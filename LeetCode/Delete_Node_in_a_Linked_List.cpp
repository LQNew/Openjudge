/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 删除指针的问题，需要勤思考，指针问题主要是要清楚指针的插入及删除！
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pNext = node->next; // 暗示了被删除的节点不是尾节点，那么找到 被删节点的下一节点，将下一节点的值赋给它，再将下一节点的next赋给当前节点
        node->val = pNext->val;
        node->next=pNext->next;
        delete pNext;
    }
};
