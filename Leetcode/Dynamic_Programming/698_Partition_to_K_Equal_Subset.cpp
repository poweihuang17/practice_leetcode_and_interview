class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=accumulate(nums.begin(),nums.end(),0);
        if(k<0 || n%k!=0) return false;
        vector<int> visited(nums.size(),0);
        sort(nums.begin(),nums.end());
        return canPartition(nums,visited,0,k,0,0,n/k);
    }

    bool canPartition(vector<int> & nums, vector<int>& visited,int start_index, int k, int cur_sum, int cur_num, int target)
    {
    	if(k==1) return true;
    	
    	if(cur_sum == target && cur_num >0 )return canPartition(nums, visited, 0, k-1, 0, 0, target);
    	
    	for(int i = start_index; i<nums.size(); i++){
            if(!visited[i]){
                visited[i] = 1;
                if(canPartition(nums, visited, i+1, k, cur_sum + nums[i], cur_num++, target))return true;
                visited[i] = 0;
            }
        }
        return false;
	}

};