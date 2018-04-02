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
    TreeNode* convertBST(TreeNode* root) {
    	int sum=0;
        helper(sum,root);
        return root;
    }

    void helper(int & sum, TreeNode * root)
    {
    	if(root==nullptr) return;

    	helper(sum,root->right);
    	int next_sum=sum+root->val;
    	root->val+=sum;
    	sum=next_sum;
    	helper(sum,root->left);
    }
};