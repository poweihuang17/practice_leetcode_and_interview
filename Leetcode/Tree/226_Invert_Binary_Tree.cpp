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
    TreeNode* invertTree(TreeNode* root) {
 		if(root==nullptr) return nullptr;

 		TreeNode * right=root->right, * left=root->left;

 		root->left=invertTree(right);
 		root->right=invertTree(left);
 		return root;
    }
};