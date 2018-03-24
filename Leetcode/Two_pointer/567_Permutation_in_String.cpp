class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	vector<int>count(26,0);
    	if(s1.size()>s2.size()) return false;
    	for(int i=0;i<s1.size();i++) 
    		{
    			count[s1[i]-'a']++;
    			count[s2[i]-'a']--;
    		}
        if(allzero(count)) return true;
    	for(int i=s1.size();i<s2.size();i++)
    	{
    		count[s2[i]-'a']--;
    		count[s2[i-s1.size()]-'a']++;
    		if(allzero(count)) return true;
    	}
    	return false;

    }

    bool allzero(vector<int> a)
    {
    	for(auto & c: a)
    		if(c!=0) return false;
    	return true;
    }
};