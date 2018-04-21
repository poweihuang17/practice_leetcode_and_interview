#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct pos{
	pos(int a,int b,int c):val(a),x(b),y(c){}

	bool operator<(const pos &d) const{return val>d.val;}

	int val,x,y;
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue< pos> q;

        q.emplace(grid[0][0],0,0);
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int level;
        while(q.size())
        {
        	level=q.top().val;
        	int i=q.top().x,j=q.top().y;
        	q.pop();
        	if(i==m-1 && j==n-1)
            {
                //cout<<"Yes";
                return level;
            }
        	visited[i][j]=true;
        	for(auto & d:dir)
        	{
        		int new_x=i+d[0];
        		int new_y=j+d[1];
        		if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && visited[new_x][new_y]==false)
        			{
        				q.emplace(max(level,grid[new_x][new_y]),new_x,new_y);
        				visited[new_x][new_y]=true;
        			}
        	}
        }
        return level;
    }
};