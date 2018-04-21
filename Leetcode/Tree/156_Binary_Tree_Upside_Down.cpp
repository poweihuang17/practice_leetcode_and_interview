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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        flip(root);
        return newroot;
    }

    void flip(TreeNode * root)
    {

    	if(root->left==nullptr)
    	{
    		newroot=root;
    		return;
    	}
    	flip(root->left);
    	root->left->right=root;
    	root->left->left=root->right;
    	root->left=nullptr;
    	root->right=nullptr;
    }
//How to avoid global variable?
private:
	TreeNode * newroot;

};