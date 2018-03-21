class Solution {
public:
    bool checkRecord(string s) {
    	unordered_map <char,int> table;
        for(int i=0;i<s.size();i++)
        {
        	table[s[i]]++;
            if(table['A']==2)
        		return false;
        	if(i+2<s.size() && s[i]=='L' && s[i+1]=='L' && s[i+2]=='L')
        		return false;
        }
        return true;

    }
};