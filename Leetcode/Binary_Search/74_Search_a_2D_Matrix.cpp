class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        int i=0, j=matrix.size()-1;
        int target_row=0;
        while(i+1<j)
        {
        	int mid=i+(j-i)/2;
        	if(matrix[mid][0]>target)
        		{
        			j=mid;
        		}
        	else if(matrix[mid][0]<target)
        		{
        			i=mid;
        		}
        	else 
                return true;
        }
        
        if (matrix[i][0]==target)
        	return true;
        if(matrix[j][0]==target)
        	return true;
        
        for(target_row=i;target_row<matrix.size() && target_row<i+2;target_row++)
        {
            int l=0;
            int m=matrix[target_row].size()-1;
            while(l+1<m)
            {
                int mid=l+(m-l)/2;
                if(matrix[target_row][mid]>target)
                    m=mid;
                else if(matrix[target_row][mid]<target)
                    l=mid;
                else
                    return true;
            }
            if (matrix[target_row][l]==target)
                return true;
            if(matrix[target_row][m]==target)
                return true;
        }
        return false;
    }
};