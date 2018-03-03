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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
    return vector<vector<int> >(result.rbegin(),result.rend());
        
    }
};


/*
It seems that java could supply linked list in an easy way...?
Maybe I should learn about java....?
All the C++ code just  do reversed....
C++: Use linked list and then output it to vector???

public class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        List<List<Integer>> wrapList = new LinkedList<List<Integer>>();
        
        if(root == null) return wrapList;
        
        queue.offer(root);
        while(!queue.isEmpty()){
            int levelNum = queue.size();
            List<Integer> subList = new LinkedList<Integer>();
            for(int i=0; i<levelNum; i++) {
                if(queue.peek().left != null) queue.offer(queue.peek().left);
                if(queue.peek().right != null) queue.offer(queue.peek().right);
                subList.add(queue.poll().val);
            }
            wrapList.add(0, subList);
        }
        return wrapList;
    }
}
*/