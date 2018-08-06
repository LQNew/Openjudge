/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//这道题给我的感觉需要对递归理解得比较好才能解决此问，然而我理解得还不是特别好 orz..
class Solution {
    int ans;
public:
    int maxPathCompute(TreeNode*root){
        if(!root) return 0;
        int left = maxPathCompute(root->left); //返回从当前节点左侧看最大的值
        int right = maxPathCompute(root->right); //返回从当前节点左侧看最大的值
        ans = max(ans,(max(0,left)+max(0,right)+root->val)); //比对原有的最大值和当前最大的路径值
        return root->val+max(0,max(left,right)); //返回从目前节点看 最大的一部分值
    }
    int maxPathSum(TreeNode* root) {
        ans=0x80000000; //最小负数的表示形式
        maxPathCompute(root);
        return ans;
    }
};
