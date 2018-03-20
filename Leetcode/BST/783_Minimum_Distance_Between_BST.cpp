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

//Solution in discuss
//This is better. Just use a pre to record the previous value.
class Solution {
  public:
    int res = INT_MAX, pre = -1;
    int minDiffInBST(TreeNode* root) {
        if (root->left != NULL) minDiffInBST(root->left);
        if (pre >= 0) res = min(res, root->val - pre);
        pre = root->val;
        if (root->right != NULL) minDiffInBST(root->right);
        return res;
    }
};