class Solution {
public:
    bool isIsomorphic(string s, string t) {
      if(s.size()!=t.size()) return false;
      else if (s.size()==0) return true;
      
      unordered_map<char,char> table;
      unordered_map<char,char> table2;

      for(int i=0;i<s.size();i++)  
      {
      	if(table.count(t[i]))
      	{
      		if(s[i]==table[t[i]])
      			continue;
      		else
      			return false;
      	}
      	else
      		{
      			if(table2.count(s[i]))
      				return false;
      			else
					{
						table[t[i]]=s[i];
						table2[s[i]]=t[i];
					}
			}
      }
      return true;
    }
};