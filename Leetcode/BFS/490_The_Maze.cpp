class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
     if(maze.empty()) return false;

     queue<pair<int,int>> myqueue;
     vector<vector<int>> mydir{ {0,1},{1,0},{0,-1},{-1,0}};
     
     int row=maze.size();
     int col=maze[0].size();
     vector<vector<bool> > visited(row, vector<bool> (col, false));


     if(start[0]>=0 && start[0]<row && start[1]>=0 && start[1]<col && !maze[start[0]][start[1]])
     	{
     		if (start[0]== destination[0] && start[1]==destination[1]) return true;
     		myqueue.push({start[0],start[1]});
     		visited[start[0]][start[1]]=true;

     	}

     while(!myqueue.empty())
     {
     	int r=myqueue.front().first;
     	int c=myqueue.front().second;


     	myqueue.pop();
     	bool result=false;

     	for(auto & dir:mydir)
     	{
     		int new_r=r+dir[0];
     		int new_c=c+dir[1];
     		while(new_r>=0 && new_r<row && new_c>=0 && new_c<col && !maze[new_r][new_c])
     		{
     			new_r=new_r+dir[0];
     			new_c=new_c+dir[1];
     		}
     		new_r-=dir[0];
     		new_c-=dir[1];

     		if(!visited[new_r][new_c])
     		{
     			myqueue.push({new_r,new_c});
     			visited[new_r][new_c]=true;
     			if (new_r== destination[0] && new_c==destination[1]) return true;
     		}
            
     	}
     }
     return false;
    }
};