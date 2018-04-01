class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        int sum=0;
        vector<int> temp;
        backtrack(candidates,ret,0,temp,sum,target);
        return ret;
    }

    void backtrack(vector<int> & candidates, vector<vector<int>> & ret, int i, vector<int>  & temp,int  & sum, int  & target)
    {
    	if(target==sum) ret.push_back(temp);
        else if(sum>target) return;
        
    	for(int k=i;k<candidates.size();k++)
    	{
    		if(k>i && candidates[k]==candidates[k-1]) continue; 
    		sum+=candidates[k];
    		temp.push_back(candidates[k]);
    		backtrack(candidates, ret, k+1, temp,sum,target);
    		sum-=candidates[k];
    		temp.pop_back();
    	}
    }
};