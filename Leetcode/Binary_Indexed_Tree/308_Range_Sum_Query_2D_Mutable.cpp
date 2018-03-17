#include <vector>
#include <iostream>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
    	if(matrix.empty()) return;
        m=matrix.size();
        n=matrix[0].size();
        tree=vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1,0));
        nums=vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(),0));
    	for(int i=0;i<nums.size();i++)
    	{
    		for(int j=0;j<nums[0].size();j++)
    		{
    			update(i,j,matrix[i][j]);
    		}
    	}
    }
    
    void update(int row, int col, int val) {
    	int change=val-nums[row][col];
    	nums[row][col]=val;
    	for(int i=row+1;i<=m;i+=i & (-i))
    	{
    		for(int j=col+1;j<=n;j+=j&(-j))
    		{
    			tree[i][j]+=change;
    		}
    	}
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    	//cout<<sum(row2+1, col2+1)<<'\n';
    	//cout<<nums[0][0]<<'\n';
        return sum(row2+1, col2+1)+sum(row1,col1)-sum(row2+1,col1)-sum(row1,col2+1);
    }

private:
	vector< vector<int> > tree;
	vector< vector<int> > nums;
	int m; //row
	int n; //column

	int sum(int row, int col)
	{
		int sum=0;
		for(int i=row;i>0;i-=i & (-i)){
			for(int j=col;j>0;j-=j&(-j))
			{
				sum+=tree[i][j];
			}
        }
		return sum;
	}

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */


int main()
{
	vector< vector<int> > test{{1}};
	NumMatrix n(test);
	cout<<n.sumRegion(0,0,0,0);


}