/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
// 求中序遍历的上一节点问题，分为左节点、右节点考虑，对于程序的书写的严谨性要求较高！！
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL) return NULL;
        TreeLinkNode* pNext = NULL;
        if(pNode->right!=NULL){
            pNext = pNode->right;
            while(pNext->left!=NULL) pNext = pNext->left;
        }
        else if(pNode->next!=NULL){ // 这一块的思路很严谨！！
            TreeLinkNode* p_parent = pNode->next;
            pNext = pNode;
            while(p_parent!=NULL && pNext==p_parent->right){
                p_parent = p_parent->next;
                pNext = pNext->next;
            }
            pNext = p_parent;
            //delete p_parent;
        }
        return pNext;
    }
};
