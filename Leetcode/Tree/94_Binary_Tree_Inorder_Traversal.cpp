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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode * > mystack;
        TreeNode * Current=root;

        while(!mystack.empty() || Current)
        {
        	if(Current)
        	{
        		mystack.push(Current);
        		Current=Current->left;
        	}
        	else
        	{
        		TreeNode * p=mystack.top();
        		ans.push_back(p->val);
        		mystack.pop();
        		Current=p->right;
        	}
        }
        return ans;
    }
};