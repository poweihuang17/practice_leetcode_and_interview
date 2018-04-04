//Boyer-Moore Majority Vote Algorithm....
//Streaming algorithm is itself a very important problem.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(count==0)
            {
                max=nums[i];
                count=1;
            }
            else if(nums[i]==max)
                count++;
            else
                count--;
        }
        return max;
    }
};