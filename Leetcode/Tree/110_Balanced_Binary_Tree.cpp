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
    bool isBalanced(TreeNode* root) {
        pair<bool,int> result=helper(root);
        return result.first;
    }

    pair<bool,int> helper(TreeNode * root)
    {
    	if(root==nullptr) return pair<bool,int>(true,0);
    	pair<bool,int> left=helper(root->left);
    	pair<bool,int> right=helper(root->right);
    	pair<bool,int> ret;
    	if(left.first==false || right.first==false)
    		ret.first=false;
    	else 
    	{
    		if(abs(left.second-right.second)>1) ret.first=false;
    		else ret.first=true;
    	}
    	ret.second=max(right.second, left.second)+1;
        return ret;
    }
    
};