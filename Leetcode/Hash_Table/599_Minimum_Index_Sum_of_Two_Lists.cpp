class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    	unordered_map<string,int> table;
    	int minimum=INT_MAX;
    	vector<string> ret;

        for(int i=0;i<list1.size();i++)
        {
        	table[list1[i]]=i;
        }

        for(int i=0;i<list2.size();i++)
        {
        	if( table.count(list2[i]) )
        	{
        		if((i+table[list2[i]])<minimum)
        		{
        				minimum=i+table[list2[i]];
        				ret=vector<string>{list2[i]};
        		}

        		else if(i+table[list2[i]]==minimum)
        		{
        				
        				ret.push_back(list2[i]);
        		}
        	}

        }
        return ret;
    }
};