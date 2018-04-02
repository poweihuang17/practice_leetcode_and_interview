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
    int findTilt(TreeNode* root) {
    	int sum=0, tiltsum=0;
        helper(sum,tiltsum,root);
        return tiltsum;
    }

    void helper(int & sum, int & tiltsum,TreeNode * root)
    {
    	if(root==nullptr) return;

    	int sum1=0, tiltsum1=0, sum2=0,tiltsum2=0;
    	helper(sum1,tiltsum1,root->right);
    	helper(sum2,tiltsum2,root->left);

    	sum=sum1+sum2+root->val;
    	tiltsum=tiltsum1+tiltsum2+abs(sum1-sum2);
    	return ;
    }
};