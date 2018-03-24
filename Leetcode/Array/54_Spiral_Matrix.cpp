#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	if(matrix.empty()) return vector<int>();
    	vector<int> ans;
        int rowbegin=0, rowend=matrix.size()-1, colbegin=0,colend=matrix[0].size()-1;

        while(rowbegin<=rowend && colbegin<=colend)
        {
        	//Move Right
        	for(int i=colbegin;i<=colend;i++)
        		{
        			ans.push_back(matrix[rowbegin][i]);
        			//cout<<matrix[rowbegin][i];
        		}
        	rowbegin++;

        	//Move Down
        	if(rowbegin<=rowend)
        	{
        		for(int i=rowbegin;i<=rowend;i++)
        		{
        			ans.push_back(matrix[i][colend]);
        			//cout<<"Down";
        			//cout<<matrix[i][colend];
        		}
        	colend--;
        	}
        	else 
        		break;


        	//Move Left
        	if(colend>=colbegin)
        		{
        		for(int i=colend;i>=colbegin;i--)
        		{
        			ans.push_back(matrix[rowend][i]);
        			//cout<<"Left";
        			//cout<<matrix[rowend][i];
        		}
        		rowend--;
        		}
        	else
        		break;

        	//Move Up
        	for(int i=rowend;i>=rowbegin;i--)
        		{
        			ans.push_back(matrix[i][colbegin]);
        			//cout<<"Up";
        			//cout<<matrix[i][colbegin]<<endl;
        		}
        	colbegin++;
        }
        return ans;
    }
};


int main()
{
	vector<vector<int>> matrix{{2,3}};
	Solution().spiralOrder(matrix);
}