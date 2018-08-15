/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 假定倒数第n个数一定存在且合情合理的前提下
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n == 0) return NULL;
        ListNode* fNode = head;
        ListNode* bNode = NULL;
        for(int i=0;i<n-1;i++) fNode = fNode->next;
        bNode = head;
        while(fNode->next!=NULL){
            fNode = fNode->next;
            bNode = bNode->next;
        }
        if(bNode->next == NULL){ // 如果 待删除的节点为尾节点
            if(head == bNode) return NULL; // 链表只有一个节点，既是尾节点又是头结点
            else{ //链表有多个节点，删除尾节点
                ListNode* tmp = head;
                while(tmp->next != bNode){
                    tmp = tmp->next;
                }
                tmp->next = bNode->next;
                delete bNode;
                bNode = NULL;
                return head;
            }
        }
        else{ //正常情况下的待删除节点
            ListNode* tmp = bNode->next;
            bNode->val = tmp->val;
            bNode->next = tmp->next;
            delete tmp;
            tmp  = NULL;
            return head;
        }
    }
};
