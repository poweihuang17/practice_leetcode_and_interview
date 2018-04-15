/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Accepted, but actually a very bad answer.
//Thank god that I have second round.
//A postorder traversal might be better.
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       	unordered_map<string,TreeNode * > duplicate;
       	vector<TreeNode *> ret;
       	find(ret,root,duplicate);
       	return ret;
    }

    void find(vector<TreeNode *> & ret, TreeNode * root,unordered_map<string,TreeNode *> & duplicate)
    {
    	if(root==nullptr) return ;

    	string s=tree2str(root);
    	if(duplicate.count(s))
        {
            if(duplicate[s]!=nullptr)
                ret.push_back(duplicate[s]);
            duplicate[s]=nullptr;
        }  
    	else
    		duplicate[s]=root;
    	find(ret,root->left,duplicate);
    	find(ret,root->right,duplicate);
    	return ;
    }

    
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