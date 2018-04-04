//After more thought, I think the problem doesn't need two counters.
//My control logic about counter is too chaotic and this is the reason which make me use two counter.
//Actually, this problem only need one problem, after more thought.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	if(words.size()==0 || s.size()==0) return vector<int>();

        int token_length=words[0].size();

        unordered_map<string,int> table;

        for(auto & word:words)
        	table[word]++;

        
        vector<int> ret;

        int count=table.size();
        int count2;
        for(int i=0;i<token_length;i++)
        {
        	unordered_map <string,int> new_table=table;
        	int begin=i,end=i;
            count=table.size();
            count2=0;
	       	while(end<s.size())
	        {
	        	string k=s.substr(end,token_length);
	        	if(new_table.count(k))
	        	{
	        		if(new_table[k]==1) count--;
                    else if (new_table[k]==0) count2++;
                    new_table[k]--;
	        		end+=token_length;
	        	}
	        	else
	        		{
	        			end+=token_length;
                        new_table=table;
                        count=table.size();
	        			begin=end;  
                        count2=0;
	        		}
	        	

	        	while(count==0)
	        	{
	        		string l=s.substr(begin,token_length);
	        		if(new_table.count(l))
	        		{
	                    if(count2==0) 
                        {
                            ret.push_back(begin);
                        }
                        if(new_table[l]==0)
                            count++;
                        
                        new_table[l]++;
                        if(new_table[l]==0) count2--;
                        begin+=token_length;
                        
	        		}
	        		
	        		
	        	}
	        }
        }

        return ret;
    }
};