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
    string tree2str(TreeNode* t) {
        string s;
        helper(s,t);
        return s;
    }
private:
	void helper(string & s, TreeNode *t)
	{
		if(t==nullptr) return;

		string s1;
		string s2;
		helper(s1,t->left);
		helper(s2,t->right);
		s=to_string(t->val);
		if(s1=="" && s2=="")
			return;
		else if(s1=="")
			s+="()("+s2+")";
		else if(s2=="")
			s+="("+s1+")";
		else
			s+="("+s1+")("+s2+")";
		return ;
	}
};