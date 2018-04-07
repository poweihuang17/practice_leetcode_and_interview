class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        
        vector<bool> record(s.size(),false);

        for(auto & word:dict)
        {
        	int start=0;
        	size_t found=s.find(word,start);
        	while(found!=string::npos)
        	{
        		for(int i=found;i<found+word.size();i++)
        			record[i]=true;
        		start=found+1;
        		found=s.find(word,start);
        	}
        }

        string ret;
        for(int i=0;i<s.size();i++)
        {
        	if(record[i]&&(i==0 || !record[i-1])) ret+="<b>";
        	ret+=s[i];
        	if(record[i]&&(i==s.size()-1 || !record[i+1])) ret+="</b>";
        }
        return ret;
    }
    
};