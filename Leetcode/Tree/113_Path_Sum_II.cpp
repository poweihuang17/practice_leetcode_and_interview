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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> ret;
    	vector<int> temp;
        backtrack(ret,temp,root,sum,0);
        return ret;
    }

    void backtrack(vector<vector<int>> & ret, vector<int> & temp, TreeNode * root, int & sum, int  current)
    {
    	if(root==nullptr) return;

    	if(root->left==nullptr && root->right==nullptr )
    	{
    		if((current+root->val)==sum)
    		{
    			temp.push_back(root->val);
    			ret.push_back(temp);
    			temp.pop_back();
    		}
    		return;
    	}
    	
    	if(root->left!=nullptr)
    	{
    			temp.push_back(root->val);
    			backtrack(ret, temp, root->left, sum,current+root->val);
    			temp.pop_back();
    	}

    	if(root->right!=nullptr)
    	{
    		temp.push_back(root->val);
    		backtrack(ret,temp,root->right,sum,current+root->val);
    		temp.pop_back();
    	}
    	return;
    }
};