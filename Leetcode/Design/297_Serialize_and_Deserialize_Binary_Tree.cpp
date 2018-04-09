/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        helper(s,root);
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	int i=0;
    	return data.size()==0? nullptr:build(data,i);
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
        string temp=s.substr(start,i-start);
        //cout<<temp<<'\n';
        if(temp=="") return nullptr;
		int num=stoi(temp);
        
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));