class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    	unordered_map< int, int> table;
    	table[0]=-1;
    	int n=0;
    	int m=0;
    	int ans=0;
    	int index=0;
        for(auto & num:nums)
        {
        	if(num==0)
        		n++;
        	else
        		m++;
    		if (table.count(n-m))
    			ans=max(ans,index-table[n-m]);
            else
    		    table[n-m]=index;
    		index++;
        }
        return ans;
    }
};