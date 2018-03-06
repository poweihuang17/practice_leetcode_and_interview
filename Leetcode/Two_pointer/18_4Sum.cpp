//Actually, I should use iterator to implement...
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	
    	sort(nums.begin(),nums.end());
    	std::vector<int>::iterator vec_start, vec_end;


    	vector<vector<int>> result;
        for(int i=1;i<=nums.size();i++)
        {
        	if( i>1 && nums[nums.size()-i]==nums[nums.size()-i+1])
        		continue;
        	vector<int> newVec(nums.begin(), nums.end()-i);
        	vector<vector<int>> three=threeSum(newVec,target-nums[nums.size()-i]);
        	for ( int j=0;j<three.size();j++)
        	{
        		three[j].push_back(nums[nums.size()-i]);
        		result.push_back(three[j]);
        	}
        	
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        if (nums.size()<3)
            return vector<vector<int>>();
        
        vector<vector<int>> result;
        

        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;

            else
            {
                int j=i+1, k=nums.size()-1;
                while(j<k)
                {
                    int s=nums[i]+nums[j]+nums[k];
                    if(s<target)
                    {
                        j+=1;
                    }
                    else if(s>target)
                    {
                        k-=1;
                    }
                    else
                    {
                        vector<int> item={nums[i],nums[j],nums[k]};
                        result.push_back(item);
                        while (j<k && nums[j]==nums[j+1])
                            j++;
                        while(j<k && nums[k]==nums[k-1])
                            k--;
                        j++;
                        k--;
                    }
                }
            }

        }
        return result;
        
    }

};