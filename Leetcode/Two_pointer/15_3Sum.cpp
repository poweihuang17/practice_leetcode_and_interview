class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size()<3)
            return vector<vector<int>>();
        
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());

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
                    if(s<0)
                    {
                        j+=1;
                    }
                    else if(s>0)
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