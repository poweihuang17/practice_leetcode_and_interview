#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue< pair<int,int>,vector< pair<int,int> >, greater<pair<int,int> > > t;
        for(int i=0;i<nums.size();i++)
        {
        	t.push({nums[i],i});
        }

        vector<string> ans(nums.size(),"");
        while(t.size()>3)
        {
        	ans[t.top().second]=to_string(t.size());
        	t.pop();
        }
        if(t.size()==3)
        {
            ans[t.top().second]="Bronze Medal";
            t.pop();
        }
        if(t.size()==2)
        {
            ans[t.top().second]="Silver Medal";
            t.pop();
        }
        if(t.size()==1)
        {
            ans[t.top().second]="Gold Medal";
            t.pop();
        }

        return ans;
    }
};

int main()
{
	vector<int> a{5,4,3,2,1};
	Solution().findRelativeRanks(a);
}