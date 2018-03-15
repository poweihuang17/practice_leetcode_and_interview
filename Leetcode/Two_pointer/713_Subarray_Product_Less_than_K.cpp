#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
     if(nums.size()==0) return 0;

     int start=0;
     int end=0;
     int number=1;
     int count=0;
     while(end<nums.size())
     {
     	
     	number*=nums[end];
     	while(start<=end && number>=k)
     	{
     		number/=nums[start++];
     	}
     	count+=(end-start+1);
     	end++;
     }

    return count;   
    }
};

int main()
{
	Solution s;
	vector<int> nums{10,5,2,6};
	vector<int> nums2{10,9,10,4,3,8,3,3,6,2,10,10,9,3};
	int k=100;
	int k2=19;
	cout<<s.numSubarrayProductLessThanK(nums,k);
	cout<<endl;
	cout<<s.numSubarrayProductLessThanK(nums2,k2);
}