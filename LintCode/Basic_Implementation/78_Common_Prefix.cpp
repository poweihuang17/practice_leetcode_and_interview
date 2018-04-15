class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if(strs.size()==0 || strs[0].size()==0) return "";
        int i=0;
        while(i<strs[0].size())
        {
        	char c=strs[0][i];
        	bool pass=true;
        	for(int j=1;j<strs.size();j++)
        	{
        		if(i<strs[j].size() && strs[j][i]==c)
        			continue;
        		else
        			{pass=false;break;}
        	}
        	if(pass) i++;
        	else break;
        }

        return strs[0].substr(0,i);
    }
};