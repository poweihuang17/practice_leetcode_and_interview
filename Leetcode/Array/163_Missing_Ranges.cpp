class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
    	vector<string> ret;
        long  start=lower;
        long  end=upper;

        for(int i=0;i<nums.size();i++)
        {
        	if(nums[i]>upper)
        		{
        			build_string(ret,start,upper);
        			return ret;
        		}
        	else if(start==nums[i])
            {
                start=nums[i];
                start++;
            }
        	else if(start<nums[i])
        	{
        		end=nums[i]-1;
        		build_string(ret,start,end);
        		start=(long)nums[i]+1;
        	}
        	else
        		continue;
        }
       
        build_string(ret,start,upper);
        return ret;
    }

private:

	void build_string(vector<string> & r,long start, long end)
	{
		string s;
       	if(start==end)
			r.push_back(to_string(start));
		else if(start>end)
			return;
		else
			r.push_back(to_string(start)+"->"+to_string(end));
	}
};