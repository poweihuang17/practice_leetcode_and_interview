#include <vector>
using namespace std;
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        if (nums.size()<=0)
    		return 0;
    	else if (nums.size()==1)
    		return nums[0]<target;
    	else if (nums.size()==2)
    		return (nums[0]+nums[1])<target;
    	
    	int count=0;
        
    	sort(nums.begin(),nums.end());

    	for(int i=0;i<nums.size()-2;i++)
    	{
            int j=i+1, k=nums.size()-1;	
			while(j<k)
			{
				int s=nums[i]+nums[j]+nums[k];
				if(s<target)
				{
					count+=(k-j);
                    j++;
				}
				else
				{
					k-=1;
				}
			}
    	}
    	return count;
    }
};