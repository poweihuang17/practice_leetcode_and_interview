class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;

        int counting[3]={0,0,0};

        for(int i=0;i<nums.size();i++)
        {
        	counting[nums[i]]++;
        }
        int j=0;
        int k=0;
        while(j<=2)
        {
        	if(counting[j]!=0){
        		nums[k++]=j;
        		counting[j]=counting[j]-1;
        	}
        	else
        	{
        		j++;
        	}
        }

    }
};