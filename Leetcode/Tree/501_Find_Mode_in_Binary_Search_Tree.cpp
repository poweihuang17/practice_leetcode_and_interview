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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> table;
    	int maxi=INT_MIN;
    	dfs(table,root,maxi);
    	vector<int> ans;
    	for(auto & p:table)
    	{
    		if(p.second ==maxi) 
    			ans.push_back(p.first);
    	}    
    	return ans;
    }

private:
	void dfs(unordered_map<int,int> & table, TreeNode * root,int & maxi){
		if(root==NULL) return;
		dfs(table, root->left,maxi);
		table[root->val]++;
		maxi=max(maxi,table[root->val]);
		dfs(table, root->right,maxi);
		return ;
	}
};

/*
Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count). 
*/