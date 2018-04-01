class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if(canPermutePalindrome(s)==false) return vector<string>();
        
        vector<char> keys;
        string forward, backward;
        string middle;
        vector<string> ret;

        for(auto & kv: table)
        {
        		if(kv.second%2) { middle+=kv.first;}
        		for(int i=0;i<kv.second/2;i++)
        			keys.push_back(kv.first);
        }

        backtrack(ret,keys,0,forward);
        //Needs processing here.
        for(int i=0;i<ret.size();i++)
        {
        	string temp=middle;
        	for(int j=0;j<ret[i].size();j++)
        	{

        		temp+=ret[i][ret[i].size()-j-1];
        	}
        	ret[i]+=temp;
        }
        return ret;
    }

    void backtrack(vector<string> & ret, vector<char> & keys, int start, string & forward){
    	if(start==keys.size())
    		{
    			ret.push_back(forward);
    			return;
    		}

    	unordered_set<char> st;

        for(int j=start;j<keys.size();j++)
        {     	
            if(st.count(keys[j])) continue;
            st.insert(keys[j]);
            swap(keys[start],keys[j]);
            forward+=keys[start];
            backtrack(ret,keys,start+1,forward);
            forward.erase(forward.size()-1,1);
            swap(keys[start],keys[j]);
        }
    	

    }

private:

	bool canPermutePalindrome(string s) {
    	for(auto & c: s)
    	{
    		table[c]++;
    	}

    	bool record=false;
    	for(auto & item:table)
    	{
    		if(record==false)
    			{
    				if(item.second%2!=0)
    					record=true;
    			}
    		else
    		{
    			if(item.second %2!=0)
    				return false;
    		}
    	}
    	return true;
        
    }

	unordered_map<char,int> table;
};