//Monotonic stack???
//monotone queue and stack
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	if(nums.size()<2)
    		return 0;

        stack<int> monotone;
        int leftbound=nums.size()-1;
        int rightbound=0;

        for(int i=0;i<nums.size();i++)
        {
        	if(monotone.empty() || nums[i]>=nums[monotone.top()]) monotone.push(i);
        	else
        	{
        		leftbound=min(leftbound,monotone.top());
        		monotone.pop();
        		i--;
        	}
        }
        monotone=stack<int>();
        for(int i=nums.size()-1;i>=0;i--)
        {
        	if(monotone.empty() || nums[i]<=nums[monotone.top()]) monotone.push(i);
        	else
        	{
        		rightbound=max(rightbound,monotone.top());
        		monotone.pop();
        		i++;
        	}
        }
        if(rightbound>=leftbound)
            return rightbound-leftbound+1;
        else
            return 0;
    }
};
//Stack in Java has clear API...
//I thought I need to get a book. Maybe like Java for C++ users.
//It seems that Java has many API that c++ don't have but actually those API are really important.
//So, maybe I should learn Java.
//Look about Alexa. A lot of jobs need java and spark.