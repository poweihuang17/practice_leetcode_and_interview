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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	if (root==NULL)
    		return vector<vector<int>>();
    	
    	queue<TreeNode * > levelorder;
    	levelorder.push(root);

    	vector<vector<int>> result;
        bool left_right=true;
    
    	while(!levelorder.empty())
    	{
    		
            int size=levelorder.size();
            vector<int> row(size);

            for (int i=0;i<size;i++)
            {
                TreeNode *  c =levelorder.front();
                levelorder.pop();
                int index=left_right? i: size-i-1;
                row[index]=c->val;

                if (c->left)
                    levelorder.push(c->left);

                if (c->right)
                    levelorder.push(c->right);
            }
            result.push_back(row);
            left_right=!left_right;
    	}
    return result;
        
    }        
    
};