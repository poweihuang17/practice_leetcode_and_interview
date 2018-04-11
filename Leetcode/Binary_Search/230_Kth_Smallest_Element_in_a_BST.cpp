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
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;
        int count_node=count(root->left);
        if(k<=count_node)
        {
            return kthSmallest(root->left,k);
        }
        else if(k==count_node+1)
            return root->val;
        else
            return kthSmallest(root->right,k-count_node-1);
    }
    
    int count(TreeNode * root)
    {
        if(root==nullptr) return 0;
        return 1+count(root->left)+count(root->right);
    }
};