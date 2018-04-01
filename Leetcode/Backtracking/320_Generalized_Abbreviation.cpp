// This problem also has bit manipulation version of solution????
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ret;
        int i=0;
        string temp;
        bool able=true;
        backtrack(0,word, temp, ret,able);
        return ret;
    }

private:
	void backtrack(int i, string & word, string & temp, vector<string> & ret, bool able)
	{
		if(i==word.size()) {
            ret.push_back(temp);
            return;
        }
        
        temp+=word[i];
        backtrack(i+1,word,temp,ret,true);
        temp.erase(temp.size()-1,1);
        
        if(able)
        {
            
            for(int k=1;k<=word.size()-i;k++)
            {
                able=false;
                //char c='0'+k;
                string temp2=to_string(k);
                temp+=temp2;
                backtrack(i+k,word,temp,ret,able);
                temp.erase(temp.size()-temp2.size(),temp2.size());              
            }
        }
	}
};