class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> table;
        for(auto & c:magazine)
        {
        	table[c]+=1;
        }
        for(auto & c:ransomNote)
        {
        	if(table.count(c))
        	{
        		table[c]--;
        		if(table[c]<0) return false;
        	}
        	else
        		return false;
        }
        return true;
    }
};