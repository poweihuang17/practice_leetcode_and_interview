class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	priority_queue< int, vector<int> , greater<int> > myqueue;
        for(int i=0;i<nums.size();i++)
        {
        	myqueue.push(nums[i]);
        	if(myqueue.size()>k)
        		myqueue.pop();

        }
        return myqueue.top();
    }
};