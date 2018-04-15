class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int ret=words.size();
        int i=-1,j=-1;

        for(int k=0;k<words.size();k++)
        {
        	if(words[k]==word1)
        	{
        		i=k;
        		if(j!=-1) ret=min(ret,i-j);
        	}
        	else if(words[k]==word2)
        	{
        		j=k;
        		if(i!=-1) ret=min(ret,j-i);
        	}
        }
        return ret;
    }
};