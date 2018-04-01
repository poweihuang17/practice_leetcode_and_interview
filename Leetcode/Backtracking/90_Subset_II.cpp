#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> temp;
        backtrack(ret, temp, nums,0);

        return ret;
    }

private:

    void backtrack(vector<vector<int>> & ret, vector<int> & temp, vector<int> & nums, int i)
    {
    	ret.push_back(temp);
    	for(int k=i;k<nums.size();k++)
    	{
    		int count=1;
			for(int m=k+1;m<nums.size();m++)
			{
				if(nums[m]!=nums[k]) break;
				count++;
			}
			//cout<<k<<' '<<count<<endl;
			for(int l=0;l<count;l++)
    			{
    				temp.push_back(nums[k]);
    				//cout<<k+count<<endl;
    				backtrack(ret, temp, nums,k+count);
    			}
    		
    		for(int l=0;l<count;l++)
    			temp.pop_back();
    		k=k+count-1;
    	}
    }
};

int main()
{
	Solution s;
	vector<int> c{1,2,2};
	s.subsetsWithDup(c);
}