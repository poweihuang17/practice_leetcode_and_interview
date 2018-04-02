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
    int findSecondMinimumValue(TreeNode* root) {
    	if(root==nullptr) return -1;
    	int x=minval(root, root->val);
    	if(x==INT_MAX)
    		return -1;
    	else
    		return x;
    }

    int minval(TreeNode *root, int x)
    {
    	if(root==nullptr) return INT_MAX;

    	if(root->val==x)
    		return min(minval(root->right,x),minval(root->left,x));
    	else
    		return root->val;
    }
};