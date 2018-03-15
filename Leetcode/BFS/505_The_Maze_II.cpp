#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
     if(maze.empty()) return false;

     //In C++, we need to put length at the first place.
     priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> > myqueue;
     vector<vector<int>> mydir{ {0,1},{1,0},{0,-1},{-1,0}};

     
     int row=maze.size();
     int col=maze[0].size();
     vector<vector<int>> visited(row, vector<int>(col, false));


     if(start[0]>=0 && start[0]<row && start[1]>=0 && start[1]<col && !maze[start[0]][start[1]])
     	{
     		if (start[0]== destination[0] && start[1]==destination[1]) return 0;
     		myqueue.push({0,start[0],start[1]});
     	}

     while(!myqueue.empty())
     {
     	vector <int> temp=myqueue.top();
     	int mylength=temp[0];
     	int r=temp[1];
     	int c=temp[2];
     	//cout<<r<<" "<<c<<endl;
        myqueue.pop();
         
        if(r==destination[0] && c==destination[1])
        	return mylength;
         
        if(!visited[r][c])
        {
        visited[r][c]=true;
       	for(auto & dir:mydir)
	     	{
	     		int new_r=r+dir[0];
	     		int new_c=c+dir[1];
	     		int new_length=mylength+1;
	     		while(new_r>=0 && new_r<row && new_c>=0 && new_c<col && !maze[new_r][new_c])
	     		{
	     			new_r=new_r+dir[0];
	     			new_c=new_c+dir[1];
	     			new_length++;
	     		}
	     		new_r-=dir[0];
	     		new_c-=dir[1];
	     		new_length--;
	     		if(mylength!=new_length && !visited[new_r][new_c])
	     			myqueue.push({new_length, new_r, new_c});
	     	}
        }

     }
     return -1;
    }
};

int main()
{
	vector<vector<int>> maze{{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
	vector<int> start{0,4};
	vector<int> end{4,4};
	Solution s;
	cout<<s.shortestDistance(maze, start, end);
}