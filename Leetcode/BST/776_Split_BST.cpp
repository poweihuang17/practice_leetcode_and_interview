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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        
        if(root==nullptr) return vector<TreeNode*>{nullptr,nullptr};

        vector<TreeNode *> bns;

        if ( root->val <=V)
        {
            bns=splitBST(root->right,V);
            root->right=bns[0];
            return vector<TreeNode *>{root,bns[1]};
        }
        else
        {
            bns=splitBST(root->left,V);
            root->left=bns[1];
            return vector<TreeNode *>{bns[0],root};
        }

    }
};