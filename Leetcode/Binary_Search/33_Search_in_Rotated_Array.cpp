#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;

        while(start<end)
        {
        	if(nums[start]<nums[end])
        		break;
        	int mid=(start+end)/2;

        	if(nums[mid]>=nums[start])
        		start=mid+1;
        	else
        		end=mid;
        }
        //Now, start is the smallest.
        //cout<<nums[start];

        int s2=0, s3=nums.size()-1;

        while(s2<=s3)
        {
        	int mid=(s2+s3)/2;
        	int realmid=(mid+start)%nums.size();
        	if(nums[realmid]==target) return realmid;
        	if(nums[realmid]<target) s2=mid+1;
        	else s3=mid-1;
        }
        return -1;
    }
};

int main(){
	Solution s;
	vector<int> c({1,3});
	int target=1;
	cout<<s.search(c,target);
}