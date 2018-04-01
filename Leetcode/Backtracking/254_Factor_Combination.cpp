class Solution {
public:
    vector<vector<int>> getFactors(int n) {
    	vector<vector<int>> ret;
    	vector<int> temp;
        backtrack(temp, ret, n);
        ret.pop_back();
        return ret;
    }

    void backtrack(vector<int> & temp, vector<vector<int>> & ret, int now)
    {
    	if(now==1) ret.push_back(temp);

    	int end=now;
    	for(int i=2;i<=end;i++)
    	{
    		if(now%i!=0) continue;
            int next=now/i;
            if(temp.size()==0 || i>=temp.back())
            {
            temp.push_back(i);
    		backtrack(temp,ret,next);
    		temp.pop_back();
            }

    	}
    }
};