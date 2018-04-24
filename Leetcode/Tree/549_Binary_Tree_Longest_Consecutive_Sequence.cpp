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
    int longestConsecutive(TreeNode* root) {
    	if(!root) return 0;
        m=INT_MIN;
        helper(root,root);
        return m;
    }
    pair<int,int> helper(TreeNode * node, TreeNode * parent)
    {
    	if(!node) return {0,0};
    	auto left=helper(node->left,node);
    	auto right=helper(node->right,node);
    	m=max(left.first+right.second+1,m);
    	m=max(left.second+right.first+1,m);
    	int inc=0;
    	int dec=0;
    	if(node->val==parent->val+1)
    		inc=max(left.first,right.first)+1;
    	else if(node->val==parent->val-1)
    		dec=max(left.second,right.second)+1;
    	return {inc,dec};
    }
private:
	int m;
};