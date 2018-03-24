/*
Fuck, this solution use O(logn) spaces....
Need to use O(1) space....
Need to think about it later.
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> rightside={};
        recursion(root, 1, rightside);
        return;
    }

    void recursion(TreeLinkNode * node, int level, vector<TreeLinkNode * > & rightside)
    {
    	if(node==NULL) return ;
    	if(level>rightside.size())
    	{
    		node->next=NULL;
    		rightside.push_back(node);
    	}
    	else
    	{
    		node->next=rightside[level-1];
    		rightside[level-1]=node;
    	}

    	if(node->right)
    		recursion(node->right, level+1, rightside);
    	if(node->left)
    		recursion(node->left,level+1, rightside);

    }
};