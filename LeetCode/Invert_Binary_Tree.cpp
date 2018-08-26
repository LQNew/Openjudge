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
    void invertTree1(TreeNode* root){ // 完成更新
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if(root->left != NULL) invertTree1(root->left);
        if(root->right != NULL) invertTree1(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode* root1 = root; // 指向树的根节点，作为记录
        invertTree1(root);
        return root1;
    }
};
