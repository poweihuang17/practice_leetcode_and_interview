/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the maximum weight node
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        if(root==nullptr) return nullptr;
        find_max(root);
        return max_node;
    }

    int find_max(TreeNode * root)
    {
    	if(root==nullptr) return 0;
    	int left=find_max(root->left);
    	int right=find_max(root->right);
    	int sum=left+right+root->val;
    	if(sum > max_count)
    		{
    		    max_node=root;
    		    max_count=sum;
    		}
    	return sum;
    }



private:
	int max_count=0;
	TreeNode * max_node=nullptr;
};