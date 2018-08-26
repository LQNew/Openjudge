/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        bool res = false;
        if(pRoot1 != NULL && pRoot2 != NULL){
            if(pRoot1->val == pRoot2->val) res = Check(pRoot1, pRoot2);
            if(!res) res = HasSubtree(pRoot1->left, pRoot2);
            if(!res) res = HasSubtree(pRoot1->right, pRoot2);
        }
        return res;
    }

    bool Check(TreeNode* root1, TreeNode* root2){
        if(root2 == NULL) return true;
        if(root1 == NULL) return false;
        if(root1->val != root2->val) return false;
        return Check(root1->left, root2->left) && Check(root1->right, root2->right);
    }
};
