class TrieNode{
public:
	TrieNode * children[26];
	string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	vector<string> ret;
    	TrieNode * root=buildTree(words);
    	for(int i=0;i<board.size();i++)
    	{
    		for(int j=0;j<board[0].size();j++)
    		{
    			dfs(board,i,j,root,ret);
    		}
    	}
    	return ret;
    }

    void dfs(vector<vector<char>> & board, int i,int j, TrieNode * root, vector<string> & res)
    {
    	if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
    	char c=board[i][j];
    	if(c=='#' || root->children[c-'a']==nullptr) return ;
    	root=root->children[c-'a'];
    	if(root->word.size()!=0) 
        {
            res.push_back(root->word);
    	    root->word="";
        }
    	board[i][j]='#';
    	dfs(board,i-1,j,root,res);
    	dfs(board,i+1,j,root,res);
    	dfs(board,i,j+1,root,res);
    	dfs(board,i,j-1,root,res);
    	board[i][j]=c;
    }

    TrieNode * buildTree(vector<string> & words)
    {
    	TrieNode * root=new TrieNode();
    	for(string & word: words)
    	{
    		TrieNode * p=root;
    		for(auto c: word)
    		{
    			if(p->children[c-'a']==nullptr)
    				p->children[c-'a']=new TrieNode();
    			p=p->children[c-'a'];
    		}
    		p->word=word;
    	}
    	return root;
    }

};