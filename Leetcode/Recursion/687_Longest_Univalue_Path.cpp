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
    int longestUnivaluePath(TreeNode* root) {
        length=0;
        helper(root);
        return length;
    }

    int helper(TreeNode * root)
    {
    	if(root==nullptr) return 0;
        int x=helper(root->right);
        int y=helper(root->left);
    	int right=root->right!=nullptr && root->right->val==root->val? x+1:0;
    	int left=root->left!=nullptr && root->left->val==root->val?y+1:0;
    	length=max(length, right+left);
    	return max(right,left);
    }

private:
	int length;
};