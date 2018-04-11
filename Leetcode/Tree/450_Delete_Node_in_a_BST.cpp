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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;

        if(root->val>key){
        	root->left=deleteNode(root->left,key);
            return root;
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        else
        {
        	if(root->right==nullptr) {
        		TreeNode * t=root;
        		//delete root;
        		return t->left;
        	}
        	else if(root->left==nullptr)
        	{
        		TreeNode * t=root;
        		//delete root;
        		return t->right;
        	}

        	TreeNode * u=minNode(root->right);
        	u->right=deleteMin(root->right);
        	u->left=root->left;
        	//delete root;
        	return u;
        }
    }

private:

	TreeNode * minNode(TreeNode * root)
	{
		while(root->left)
		{
			root=root->left;
		}
		return root;
	}

	TreeNode * deleteMin(TreeNode * root)
	{
		if(root->left==nullptr) {
			TreeNode * t=root->right;
			//delete root;
			return t;
		}
		root->left=deleteMin(root->left);
		return root;
	}
};