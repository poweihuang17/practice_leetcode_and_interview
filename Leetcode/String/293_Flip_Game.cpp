class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
    	vector<string> ans;
        for(int i=0;i<s.size();i++)
        {
        	string temp=s;
        	if(i+1<s.size() && s[i]=='+' && s[i+1]=='+')
        		{
        			temp[i]='-';
        			temp[i+1]='-';
                    ans.push_back(temp);
        		}
        	
        }
        return ans;
    }
};