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
    int closestValue(TreeNode* root, double target) {
        
        int a=root->val;
        auto kid=target<a? root->left : root->right;
        if(!kid) return a;
        int b=closestValue(kid,target);
        return abs(a-target)<abs(b-target)? a: b;      
    }
};