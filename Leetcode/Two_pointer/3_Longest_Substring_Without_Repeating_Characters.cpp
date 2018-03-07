
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	unordered_set<char> myset;
    	int left=0;
    	int result=0;
        for(int i=0;i<s.size();i++)
        {
        	if(myset.find(s[i])==myset.end())
        	{
        		myset.insert(s[i]);
        		result=i-left+1>result? i-left+1:result; 
        	}
        	else
        	{
        		while(s[left]!=s[i])
        		{
        			myset.erase(s[left]);
        			left++;
        		}
        		left++;
        	}
        }
        return result;
    }
};