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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        helper(ret,root);
        return ret;
    }

    int helper(vector<vector<int> >& ret, TreeNode * root){
    	if(root==nullptr) return 0;
    	int height=max(helper(ret,root->right),helper(ret,root->left))+1;
    	if(height>ret.size()) ret.push_back(vector<int>(1,root->val));
    	else
    		ret[height-1].push_back(root->val);
    	return height;
    }
};