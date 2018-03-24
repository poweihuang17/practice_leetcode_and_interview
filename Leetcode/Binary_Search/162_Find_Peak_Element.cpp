class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	return findPeak(nums, 0,nums.size()-1);
    }

    int findPeak(vector<int> & nums, int begin, int end)
    {
        int i=begin, j=end;
        if(i==j) return i;
        else while(i<j)
        {
        	int mid1=(i+j)/2;
        	int mid2=mid1+1;
        	if(nums[mid2]>nums[mid1])
        		return findPeak(nums,mid2,end);
        	else
        		return findPeak(nums,begin,mid1);
        }
    }
};