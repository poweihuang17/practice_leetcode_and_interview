#include <unistd.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()<2) return 0;
        int count=0;

        for(int i=0,j=0;i<nums.size();i++)
        {
        	for (j=max(i+1,j);j<nums.size() && nums[j]-nums[i]<k;j++) ;
        	if(j<nums.size() && nums[j]-nums[i]==k) count++;
        	while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }

        return count;
    }
};

int main()
{
	vector<int> a{1,3,1,5,4};
	int k=0;
	Solution s;
	s.findPairs(a,k);
}