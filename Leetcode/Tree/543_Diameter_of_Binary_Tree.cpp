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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int case1=depth(root->left)+depth(root->right);
        int case2=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        return max(case1,case2);
    }

    int depth(TreeNode * root)
    {
    	if(root==NULL) return 0;
    	return max(depth(root->right),depth(root->left))+1;
    }
};