class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>  ret;
        vector<int>  temp;

        backtrack(ret, temp,1,n,0,k);
        return ret;
    }
private:
	void backtrack(vector<vector<int>> & ret, vector<int> & temp, int now,int n,int step,int k)
	{
		if(step==k)
			ret.push_back(temp);
		
		for(int i=now;i<=n;i++)
		{
			temp.push_back(i);
			backtrack(ret, temp, i+1,n,step+1,k);
			temp.pop_back();
		}
	}
};