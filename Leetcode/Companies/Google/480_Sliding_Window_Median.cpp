//Question about iterator updating multiset: Will the iterator change after an insert?
//Need to learn more about iterators in C++...
//Need to go back to this question later.
//Multiset Leetcode....
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> p(nums.begin(),nums.begin()+k);

        vector<double> ret;
        auto mid=next(p.begin(),(k/2));
        for(int i=k;;i++)
        {
        	ret.push_back( (*(mid)+*(prev(mid,(k-1)%2) ) )/2.0 );
        	if(i==nums.size())
        		return ret;

        	p.insert(nums[i]);

        	if(nums[i]<*mid)
        	{
        		mid--;
        	}
        	if(nums[i-k]<= *mid)
        	{
        		mid++;
        	}
        	p.erase(p.lower_bound(nums[i-k]));
        }
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,3,-1,-3,5,3,6,7};
	int k=3;
	s.medianSlidingWindow(nums,k);
}