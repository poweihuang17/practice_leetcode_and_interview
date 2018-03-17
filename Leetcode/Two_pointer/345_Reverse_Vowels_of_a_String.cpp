class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        string sl="aeiouAEIOU";
        set<char> m( sl.begin(), sl.end() );
        while(i<j)
        {
        	if(m.count(s[i]) && m.count(s[j]))
                {   
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
            
        	else if(m.count(s[i]))
        		j--;
        	else if (m.count(s[j]))
        		i++;
            else
            {
                i++;
                j--;
            }
        }
        return s;
    }
};