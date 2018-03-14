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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode * > myqueue;
        myqueue.push(root);
        vector<int> result;
        int last_value;
        while(!myqueue.empty())
        {
        	int level_size=myqueue.size();
        	last_value=myqueue.front()->val;
        	for(int i=0;i<level_size;i++)
        	{
        		TreeNode * temp=myqueue.front();
        		myqueue.pop();
                if(temp->left)
        			myqueue.push(temp->left);
        		if(temp->right)
        			myqueue.push(temp->right);

        	}
        }
        return last_value;
    }
};