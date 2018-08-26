/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool Check(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true; // 如果都指向了空指针，说明已经到达了叶节点处且并未发生不symmetic 的情况
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;
        return Check(root1->left, root2->right) && Check(root1->right, root2->left); // 左边和右边比对 以及 右边和左边比对
    }

    bool isSymmetric(TreeNode* root) {
        return Check(root, root);

    }
};
