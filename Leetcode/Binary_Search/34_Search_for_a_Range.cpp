class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size()==0 ) return vector<int>{-1,-1};
        
        int i=0,j=nums.size()-1;
        int left=-1,right=-1;
        while(i+1<j)
        {
        	int mid=i+(j-i)/2;
        	if(target>nums[mid])
        		i=mid;
        	else if(target<=nums[mid])
        		j=mid;
        }

        if(target==nums[i])
        	left=i;
        else if(target==nums[j])
        	left=j;
        else
        	return vector<int>{-1,-1};

        i=0;j=nums.size()-1;
        while(i+1<j)
        {
        	int mid=i+(j-i)/2;
        	if(target>=nums[mid])
        		i=mid;
        	else
        		j=mid;
        }
        if(target==nums[j])
        	right=j;
        else if (target==nums[i])
        	right=i;

        return vector<int>{left,right};
    }
};