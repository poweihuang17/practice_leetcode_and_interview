/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Vector destructor?
//C++ destructor?

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> table;
        ret.clear();
        max_value=0;
        helper(table,root);
        return ret;
    }

    int helper(unordered_map<int,int> & table, TreeNode * root)
    {
    	if(root==nullptr) return 0;
    	int sum=root->val;
    	if(root->left)
    	{
    		sum+=helper(table,root->left);
    	}
    	if(root->right)
    	{
    		sum+=helper(table, root->right);
    	}
    	table[sum]+=1;
    	if(table[sum]>max_value)
    	{
    		ret=vector<int>(1,sum);
            max_value=table[sum];
    	}
    	else if (table[sum]==max_value)
    		ret.push_back(sum);

    	return sum;
    }

private:
	int max_value;
	vector<int> ret;
};