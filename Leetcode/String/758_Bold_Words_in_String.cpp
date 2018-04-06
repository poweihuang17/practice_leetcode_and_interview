//Not sure about the complexity of STL find...
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<bool> record(S.size(),false);

        for(auto & word:words)
        {
        	int start=0;
        	size_t found=S.find(word,start);
        	while(found!=string::npos)
        	{
        		for(int i=found;i<found+word.size();i++)
        			record[i]=true;
        		start=found+1;
        		found=S.find(word,start);
        	}
        }

        string ret;
        for(int i=0;i<S.size();i++)
        {
        	if(record[i]&&(i==0 || !record[i-1])) ret+="<b>";
        	ret+=S[i];
        	if(record[i]&&(i==S.size()-1 || !record[i+1])) ret+="</b>";
        }
        return ret;
    }
};