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
    int minDiffInBST(TreeNode* root) {
        vector<int> tree;
        inorder(tree,root);
        int difference=INT_MAX;
        for(int i=0;i<tree.size()-1;i++)
        {
        	difference=min(difference,tree[i+1]-tree[i]);
        }
        return difference;
    }

    void inorder(vector <int> & c, TreeNode * root)
    {
    	if(root->left) inorder(c,root->left);
    	c.push_back(root->val);
    	if(root->right) inorder(c,root->right);
    }
};