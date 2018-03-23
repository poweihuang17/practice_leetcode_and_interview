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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        	return true;
        return validate(root,LONG_MIN, LONG_MAX);

    }
private:
	bool validate(TreeNode * root, long int lower, long int upper)
	{
		
		
		if(root->val<=lower || root->val>=upper) return false;

		bool result=true;
        if(root->left)
        	result=result && validate(root->left,lower,min((long int)root->val,upper) ) ;
        if(root->right)
        	result=result && validate(root->right,max(lower,(long int)root->val), upper);
        return result;
	}
};
