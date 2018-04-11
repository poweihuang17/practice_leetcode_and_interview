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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }

    TreeNode * helper(vector<int> & preorder, int i,int j, vector<int> & inorder,int k,int l)
    {
    	if(i==j) return nullptr;

    	TreeNode * t=new TreeNode(preorder[i]);
    	auto u=find(inorder.begin()+k,inorder.begin()+l,preorder[i]);
    	t->left=helper(preorder,i+1,i+u-inorder.begin()-k+1,inorder,k,u-inorder.begin());
    	t->right=helper(preorder,i+u-inorder.begin()-k+1,j,inorder,u-inorder.begin()+1,l);
    	return t;
    }
};