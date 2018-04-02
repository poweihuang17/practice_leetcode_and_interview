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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	TreeNode * x=buildTree(nums,0,nums.size()-1);
    	return x;
    }

    TreeNode * buildTree(vector<int> & nums, int i,int j)
    {
    	if(i>j) return nullptr;
        
        int t=(i+j)/2;
    	TreeNode * root=new TreeNode(nums[t]);
    	TreeNode * left=buildTree(nums,i,t-1);
    	TreeNode * right=buildTree(nums,t+1,j);
    	root->right=right;
    	root->left=left;
    	return root;
    }
};