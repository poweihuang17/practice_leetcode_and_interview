class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        int n=strs.size();
        int i=0;
        string ret;
        

        int size=INT_MAX;
        for(int j=0;j<n;j++)
        	size=min((int)strs[j].size(),size);

        for(int k=0;k<size;k++)
        {
        	bool flag=true;
        	for(int j=1;j<n;j++)
        	{
        		if(strs[j][k]!=strs[0][k]) {flag=false;break;}
        	}
        	if(flag)
        		ret+=strs[0][k];
        	else 
        		break;
        }
        return ret;
    }
};