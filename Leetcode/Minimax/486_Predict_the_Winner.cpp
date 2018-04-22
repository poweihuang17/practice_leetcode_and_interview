class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> table(nums.size(),vector<int>(nums.size(),INT_MAX));

        for(int i=0;i<nums.size();i++)
        	table[i][i]=nums[i];

        for(int i=1;i<nums.size();i++)
        	{
        		for(int j=0;j<nums.size()-i;j++)
        		{
        			table[j][i+j]=max(nums[j]-table[j+1][j+i],nums[i+j]-table[j][i+j-1]);
        		}
        	}
        /*
        for(auto & row:table)
        {
            for(auto & item:row)
            {
                cout<<item<<" ";
            }
            cout<<endl;
        }
        */
        return table[0][nums.size()-1]>=0;
    }
};