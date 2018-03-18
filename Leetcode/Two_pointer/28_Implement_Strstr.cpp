class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()==0 && needle.size()==0) return 0;
        for(int i=0;i<haystack.size();i++)
        {
        	int count=0;
        	for(int j=0;j<needle.size();j++)
        	{
        		if(i+j<haystack.size() && haystack[i+j]==needle[j]) count++;
        	}
        	if(count==needle.size()) return i;
        }
        return -1;
    }
};