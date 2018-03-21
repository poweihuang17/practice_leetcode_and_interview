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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
            return vector<string>();
    	vector<string> res;
        if(root->left!=NULL) {
            vector<string> a=binaryTreePaths(root->left);
            for(auto & s1: a)
        	    res.push_back(to_string(root->val)+"->"+s1);
        }
        if(root->right!=NULL) {
            vector<string> b=binaryTreePaths(root->right);
            for(auto & s2: b)
        	    res.push_back(to_string(root->val)+"->"+s2);
            }
        if(root->right ==NULL && root->left==NULL)
            res.push_back(to_string(root->val));
        return res;
    }
};