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
    TreeNode* str2tree(string s) {
    	int i=0;
    	return s.size()==0? nullptr:build(s,i);
    }

private:
	TreeNode * build(string &s, int &i)
	{
		int start=i;
		if(s[i]=='-')
		{
			i++;
		}

		while(isdigit(s[i]))
		{
			i++;
		}
		it (s.substr(start,i-start)=="") return nullptr;
		int num=stoi(s.substr(start,i-start));
		TreeNode * node= new TreeNode(num);
		if(s[i]=='(')
		{
			node->left=build(s,++i);
			i++;
		}
		if(s[i]=='(')
		{
			node->right=build(s,++i);
			i++;
		}
		return node;
	}
};