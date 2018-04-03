class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int i=-1,j=-1,value=INT_MAX;
        	if(word1!=word2)
        	{
		        for(int k=0;k<words.size();k++)
		        {
		        	if(words[k]==word1)
		        	{
		        			i=k;
		        			if(j!=-1)
		        				value=min(i-j,value);
		        	}
		        	if(words[k]==word2)
		        	{
		        		j=k;
		        		if(i!=-1)
		        			value=min(j-i,value);
		        	}
		        }
		    }
		    else
		    {
		    	for(int k=0;k<words.size();k++)
		    	{
		    		if(words[k]==word1)
		    			if(i==-1)
		    				i=k;
		    			else
		    			{
		    				value=min(value,k-i);
		    				i=k;
		    			}

		    	}
		    }
        return value;
    }
};