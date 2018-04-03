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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> prefix_table;
        count=0;
        prefix_table[0]=1;
       	backtrack(prefix_table,root,sum,0);
        return count;
    }

private:

	int count;

    void backtrack(unordered_map<int,int> & prefix_table, TreeNode * root, int & sum, int prefix )
    {
    	if(root==nullptr) return;
    
        prefix+=root->val;
		count+=prefix_table[prefix-sum];
        
    	prefix_table[prefix]+=1;

		backtrack(prefix_table,root->left,sum,prefix);
		backtrack(prefix_table,root->right,sum,prefix);
        
        prefix_table[prefix]-=1;
    	return ;
    }

};