class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size()==0 || nums[0].size()==0) return nums;
        else if (nums.size()*nums[0].size()!=r*c) return nums;

        vector< vector<int>> ret(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
        	for(int j=0;j<c;j++)
        	{
        		ret[i][j]=nums[(i*c+j)/nums[0].size()][(i*c+j)%nums[0].size()];
        	}
        }
        return ret;
    }
};