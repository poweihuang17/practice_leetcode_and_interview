//How to implement deque?
#include <deque>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> q;
		vector<int> ret;

		if(k>nums.size())
		{
			int i=*max_element(nums.begin(),nums.end());
			return vector<int>(nums.size(),i);
		}

		for(int i=0;i<nums.size();i++)
		{
			while(!q.empty() && q.front()<i-k+1)
				q.pop_front();
			while(!q.empty() && nums[q.back()]<nums[i])
				q.pop_back();
            q.push_back(i);
			if(i>=k-1) ret.push_back(nums[q.front()]);
		}
		return ret;
    }
};