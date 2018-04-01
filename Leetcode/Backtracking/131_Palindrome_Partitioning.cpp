//How to analyze the complexity of this algorithm?

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> temp;
        backtrack(s,ret,temp, 0);
        return ret;
    }
private:

	void backtrack(string  & s, vector<vector<string>> & ret, vector<string> & templist, int start)
	{
        if(start==s.size())
        {
            ret.push_back(templist);
            return;
        }
		for(int i=1;i<=s.size()-start;i++)
		{
			string temp=s.substr(start,i);
			if( isPalindrome(temp,0,temp.size()-1) )
			{
                templist.push_back(temp);
				backtrack(s, ret, templist, start+i);
                templist.pop_back();
			}
		}
	}

	bool isPalindrome(string s, int i,int j)
	{
		while(i<j)
		{
			if(s[i++]!=s[j--]) return false; 
		}
		return true;
	}
};