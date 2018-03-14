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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return vector<int>();

        queue<TreeNode * > myqueue;
        myqueue.push(root);
        vector<int> result;

        while(!myqueue.empty())
        {
        	int level_size=myqueue.size();
        	int max_value=INT_MIN;
        	for(int i=0;i<level_size;i++)
        	{
        		TreeNode * temp=myqueue.front();
        		myqueue.pop();
        		max_value=max(temp->val,max_value);
        		if(temp->right)
        			myqueue.push(temp->right);
        		if(temp->left)
        			myqueue.push(temp->left);
        	}
        	result.push_back(max_value);
        }
        return result;
    }
};