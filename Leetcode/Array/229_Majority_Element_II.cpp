//https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       	if(nums.size()==0)
       		return vector<int>();
       	int count1=0,count2=0,candidate1=0,candidate2=1;

       	for(int i=0;i<nums.size();i++)
       	{
       		if(nums[i]==candidate1)
       			count1++;
       		else if (nums[i]==candidate2)
       			count2++;
       		else if (count1==0)
            {
                candidate1=nums[i];
                count1=1;
            }
       		else if (count2==0)
            {
                candidate2=nums[i];
                count2=1;
            }
       		else
       		{
       			count1--;
       			count2--;
       		}
       	}

       	vector<int> ret;
       	int real_count1=count(nums.begin(),nums.end(),candidate1);
       	int real_count2=count(nums.begin(),nums.end(),candidate2);
       	if(real_count1>nums.size()/3)
       		ret.push_back(candidate1);
       	if(real_count2>nums.size()/3)
       		ret.push_back(candidate2);
       	return ret;
    }
};