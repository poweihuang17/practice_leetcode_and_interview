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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	unordered_map<int,int> table;
    	for(int i=0;i<inorder.size();i++)
    		table[inorder[i]]=i;
    	return buildTreePost(table,inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }

private:
	TreeNode * buildTreePost(unordered_map<int,int> & table, vector<int>  & inorder, int is, int ie, vector<int> & postorder, int ps, int pe)
	{
		if(ps>pe || is>ie) return nullptr;
		int root_number= table[postorder[pe]];
		TreeNode * c= new TreeNode(postorder[pe]);
		c->left=buildTreePost(table,inorder,is,root_number-1,postorder,ps,ps+root_number-1-is);
		c->right=buildTreePost(table,inorder,root_number+1, ie, postorder, ps+root_number-is, pe-1);
		return c;
	}
};