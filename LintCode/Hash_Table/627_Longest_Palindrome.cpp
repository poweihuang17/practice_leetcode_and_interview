class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // write your code here
        int count[52]={0};
        for(auto & c:s)
        {
            if(c>='A' && c<='Z')
        	    count[c-'A']++;
        	else if(c>='a' && c<='z')
        	    count[26+c-'a']++;
        }
        int ret=0;
        bool need=true;
        for(int i=0;i<52;i++)
        {
        	if(count[i]%2==1)
        	{
        		ret+=count[i]-1+need;
        		need=false;
        	}
        	else
        		ret+=count[i];
        }
        return ret;
    }
};