class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<=k)
        	return std::accumulate(nums.begin(),nums.end(),0.0)/(double)k;
        
        double d=double(k);
        double temp=std::accumulate(nums.begin(),nums.begin()+k,0.0);
        double window= temp/d;//std::numeric_limits<double>::lowest();
        for(int i=1;i+k<=nums.size();i++)
        {
            temp=temp-nums[i-1]+nums[i+k-1];
        	window=max(window,temp/d);
            
        }
        return window;
    }
};