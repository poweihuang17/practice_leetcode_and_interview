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
    int getMinimumDifference(TreeNode* root) {
    	

        if(root==NULL) return mini;
        getMinimumDifference(root->left);
        if(prev!=INT_MAX)
        {
        	mini=min(mini,root->val-prev);
        }
        prev=root->val;
        getMinimumDifference(root->right);
        return mini;
    }
private:
	int mini=INT_MAX;
	int prev=INT_MAX;
};