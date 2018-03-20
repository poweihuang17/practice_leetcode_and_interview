class Solution {
public:
    bool detectCapitalUse(string word) {
    	bool c1=true,c2=true,c3=true;
        for(int i=0;i<word.size();i++)
        {
        	if(!isupper(word[i]))
        		c1=false;
        	if(isupper(word[i]))
        		c2=false;
        	if(i>0 && isupper(word[i]) )
        		c3=false;
        }
        return c1||c2||c3;
    }
};