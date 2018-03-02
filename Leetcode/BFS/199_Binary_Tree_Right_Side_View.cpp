#include <unordered_map>
#include <string>
#include <iostream>
#include <queue>
#include <utility>
#include <stack>
using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> result={};
        
        recursion(root, 1,result);
        return result;
    }

    void recursion(TreeNode * node, int level, vector<int> & result)
    {
    	if(node==NULL) return ;
    	
    	if (level>result.size()) result.push_back(node->val);

    	if(node->right)
    		recursion(node->right, level+1, result);
    	if(node->left)
    		recursion(node->left,level+1, result);
    }
};