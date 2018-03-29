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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr)
        	return s==t;
        else if( isSame(s,t))
        	return true;
        else
        	return isSubtree(s->right,t) || isSubtree(s->left,t);
    }

    bool isSame(TreeNode *s, TreeNode * t)
    {
    	if (s==nullptr && t==nullptr)
    		return true;
    	else if (s==nullptr && t!=nullptr)
    		return false;
    	else if (s!=nullptr && t==nullptr)
    		return false;
    	else if( s->val != t->val)
    		return false;

    	return isSame(s->right, t->right) && isSame(s->left, t->left);
    }
};