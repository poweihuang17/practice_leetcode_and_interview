#include <unordered_map>
#include <string>
#include <iostream>
#include <queue>
#include <utility>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
    	if (root==NULL)
    		return vector<vector<int>>();
    	int depth=1;
    	queue<pair<int,TreeNode *> > levelorder;

    	levelorder.push(pair<int,TreeNode *> (depth,root));

    	vector<vector<int>> result;

    	while(!levelorder.empty())
    	{
    		pair<int,TreeNode * > c =levelorder.front();
    		levelorder.pop();
    		depth=c.first;
    		if ((c.first)>result.size())
    			{
    				vector<int> d={c.second->val};
    				result.push_back(d);
    			}
    		else
	    		{
	    			result[depth-1].push_back(c.second->val);
	    		}
	    	if (c.second->left)
	    		levelorder.push(pair<int,TreeNode *>(c.first+1,c.second->left));
	    	if (c.second->right)
	    		levelorder.push(pair<int,TreeNode *>(c.first+1, c.second->right));
    	}
    return result;
        
    }
};