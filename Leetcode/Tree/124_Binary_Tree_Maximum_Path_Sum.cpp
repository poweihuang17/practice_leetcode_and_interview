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
    int maxPathSum(TreeNode* root) {
        max_=INT_MIN;
        pathsum(root);
        return max_;
    }

    int pathsum(TreeNode * root)
    {
    	if(root==nullptr) return 0;
    	
    	int right=0,left=0;
    	int sum=root->val;
    	int ret=0;
    	

    	if(root->right)
    		{
    			right=pathsum(root->right);
    			sum+=right;
    			ret=max(ret,right+root->val);
    		}

    	if(root->left)
    		{
    			left=pathsum(root->left);
    			sum+=left;
    			ret=max(ret,left+root->val);
    		}
        ret=max(ret,root->val);
    	max_=max(max_,sum);
		return ret;
    }

private:
	int max_;
};