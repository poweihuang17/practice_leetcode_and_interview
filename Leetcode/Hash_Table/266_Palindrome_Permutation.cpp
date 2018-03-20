class Solution {
public:
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
private:
	unordered_map<char,int> table;
};