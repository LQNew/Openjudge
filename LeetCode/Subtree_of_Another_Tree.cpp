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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL) return false;
        if(Check(s, t)) return true; // 检测从s节点以及 t节点来看是否为一个子树
        return isSubtree(s->left, t) || isSubtree(s->right, t); // 否则从s的左子树或者 是s的右子树来看
    }

    bool Check(TreeNode* root1, TreeNode* root2){
        if(root2 == NULL && root1 == NULL) return true; // 必须t为s的叶节点处的子树才可，不可为中间一段这样类型的
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;
        return Check(root1->left, root2->left) && Check(root1->right, root2->right);
    }
};
