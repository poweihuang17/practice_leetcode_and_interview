class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {

    	if(M.size()==0 || M[0].size()==0) return M;

        vector<vector<int>> direction{  {0,1} , {0,-1} , {1,0} , {-1,0} , {1,1} , {1,-1}, {-1,1},{-1,-1} };
        vector<vector<int>> ret(M);

        for(int i=0;i<M.size();i++)
        {
        	for(int j=0;j<M[0].size();j++)
        	{
        		int sum=M[i][j];
        		int count=1;
        		for(auto & v:direction)
        		{
        			int new_i=i+v[0];
        			int new_j=j+v[1];

        			if(new_i>=0 && new_i<M.size() && new_j>=0 && new_j<M[0].size())
        				{
        					sum+=M[new_i][new_j];
        					count++;
        				}
        		}
        		ret[i][j]=sum/count;
        	}
        }
        return ret;
    }
};