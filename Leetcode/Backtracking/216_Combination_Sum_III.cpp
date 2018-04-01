class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> candidates{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ret;
        int sum=0;
        vector<int> temp;
        backtrack(candidates,ret,0,temp,sum,n,k);
        return ret;
    }

    void backtrack(vector<int> & candidates, vector<vector<int>> & ret, int i, vector<int>  & temp,int  & sum, int  & target,int number)
    {
    	if(target==sum && number==0) {
    		ret.push_back(temp);
    		return ;
    	}
        else if(sum>target || number<0) return;
        
    	for(int k=i;k<candidates.size();k++)
    	{
    		if(k>i && candidates[k]==candidates[k-1]) continue; 
    		sum+=candidates[k];
    		temp.push_back(candidates[k]);
    		backtrack(candidates, ret, k+1, temp,sum,target,number-1);
    		sum-=candidates[k];
    		temp.pop_back();
    	}
    }

};