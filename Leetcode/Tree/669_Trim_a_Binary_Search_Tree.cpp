/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Question; How to delete the node in trees?
// Maybe I should use Java. Then, I don't need to worry about 
// these memories every day!
// Java v.s. C++ pros and cons
// Maybe I should learn java for backend engineer job.
// Go....

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return nullptr;

        if(root->val<L) 
        	{
        		//deletetree(root->left);
        		//delete root;
        		return trimBST(root->right,L,R);
        	}

        if(root->val>R) 
        	{
        		//deletetree(root->right);
        		//delete root;
        		return trimBST(root->left,L,R);
        	}

        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        return root;
    }

};