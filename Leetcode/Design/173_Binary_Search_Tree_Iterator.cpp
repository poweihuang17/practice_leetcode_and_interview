/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mystack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * temp=mystack.top();
        mystack.pop();
        pushAll(temp->right);
        return temp->val;
    }
private:
	stack<TreeNode *> mystack;

	void pushAll(TreeNode * node)
	{
		for(;node!=NULL;mystack.push(node),node=node->left);
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */