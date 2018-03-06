#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        unordered_map<int,int>::iterator iter;
        vector <int> result(2);

        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            iter=hashTable.find(target-x);
            if(iter!=hashTable.end())
            {
                result[0]=iter->second;
                result[1]=i;
            }
            else
            {
                hashTable[nums[i]]=i;
            }
        }

        return result;
    }
};

int main()
{
	Solution s= Solution();
	vector<int> nums={-12,25,-20,-22,12,-39,11,-15,25,47,-24,18,21,-21,32,-11,-35,37,-8,-18,42,17,16,-46,-27,-34,43,31,-13,44,-6,10,19,12,-11,-12,-25,-39,40,36,-19,-43,12,42,-39,3,-33,-5,0,48,-34,-41,-18,16,43,43,21,-1,-7,7,-13,26,17,-33,-47,23,-7,38,-4,-29,-40,-11,-6,-34,-32,46,25,-6,22,0,-45,-20,-36,3,-46,39,15,19,28,0,29,9,34,22,-8,1,-28,0,40,47,-20,20,3,-42,14,-1,-38,31,40,-31,-26,41,16,-30,-20,24,2,8,32,42,2,4,-50,30,-11,-50,-9,-38,41,-28,-44,-8,27,-35,-8,19,-36,29,-21,24,-43,-30,-11,48,30,49,26,-32,-41,39,40,-46,-28,-15,2,23,-39,-28,-15,42,-1,44,-46,-9,-6,39,9,37,-49,3,14,43,-36,-46,23,2,-6,-48,6,6,40,25,47,2,11,-13,29,24,-21,26,-19,-8,-31,-30,-20,-18,-13,-27,-47,-11};
	s.twoSum(nums,-20);
}