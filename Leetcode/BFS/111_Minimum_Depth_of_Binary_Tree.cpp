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
    int minDepth(TreeNode* root) {
        
        if (root==NULL)
    		return 0;
    	int depth=1;
    	int minimum=INT_MAX;
    	queue<pair<int,TreeNode *> > levelorder;

    	levelorder.push(pair<int,TreeNode *> (depth,root));

    	vector<vector<int>> result;

    	while(!levelorder.empty())
    	{
    		pair<int,TreeNode * > c =levelorder.front();
    		levelorder.pop();
    		depth=c.first;
    		if ((c.second->left)==nullptr && (c.second->right)==nullptr)
    			minimum=min(depth,minimum);

    		if (c.second->left)
	    		levelorder.push(pair<int,TreeNode *>(c.first+1,c.second->left));
	    	if (c.second->right)
	    		levelorder.push(pair<int,TreeNode *>(c.first+1, c.second->right));
    	}
    	return minimum;
    }
};