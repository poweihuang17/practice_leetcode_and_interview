class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	if(numRows<=0) return vector<vector<int>>();
    	int n=numRows;
    	numRows=max(4,numRows);

        vector<vector<int>> ret(numRows);
        ret[0].push_back(1);
        ret[1].push_back(1);ret[1].push_back(1);
        for(int i=2;i<numRows;i++)
        {
        	ret[i].push_back(1);
        	for(int j=0;j<ret[i-1].size()-1;j++)
        	{	
        		int sum=ret[i-1][j]+ret[i-1][j+1];
        		ret[i].push_back(sum);
        	}
        	ret[i].push_back(1);
        }

        if(n>4)
        	return ret;
        else
        	return vector<vector<int>>(ret.begin(),ret.begin()+n);
    }
};