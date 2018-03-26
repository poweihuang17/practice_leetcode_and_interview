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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> bfs;
        bfs.push(root);
        vector<double> ans;
        while(!bfs.empty())
        {
        	int temp=bfs.size();
        	double sum=0;
        	for(int i=0;i<temp;i++)
        	{
        		TreeNode * r=bfs.front();
        		sum+=r->val;
        		bfs.pop();
        		if(r->right)
        			bfs.push(r->right);
        		if(r->left)
        			bfs.push(r->left);
        	}
        	ans.push_back(sum/temp);
        }
        return ans;
    }
};