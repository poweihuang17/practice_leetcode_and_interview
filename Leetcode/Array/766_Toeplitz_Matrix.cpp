class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
     if(matrix.empty()) return false;
     int m=matrix.size();
     int n=matrix[0].size();

     for(int i=0;i<m;i++)
     {
     	
     	int x=matrix[i][0];
     	for(int j=1;i+j<m && j<n;j++)
     	{
     		if(x!=matrix[i+j][j])
     			return false;
     	}     	
     }

     for(int j=1;j<n;j++)
     {
     	int y=matrix[0][j];
     	for(int i=1;i+j<n && i<m;i++)
     	{
     		if(y!=matrix[i][i+j])
     			return false;
     	}
     }

     return true;   
    }
};