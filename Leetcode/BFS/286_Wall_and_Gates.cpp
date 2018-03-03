class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
    	if (rooms.size()==0)
    		return;

    	vector<vector<bool>> visited(rooms.size(),vector<bool>(rooms[0].size(),false));

    	for(int i=0;i<rooms.size();i++)
    	{
    		for( int j=0;j<rooms[i].size();j++)
    		{
    			if(rooms[i][j]==0)
    			{
    				dfs(i,j,rooms,0,visited);
    			}
    		}
    	}
        
    }

    void dfs(int i , int j, vector<vector<int>>& rooms, int step , vector<vector<bool>>  & visited)
    {
    	if(rooms[i][j]!=-1)
    	{
    		if (rooms[i][j]<step)
    			return;
    		else
    			rooms[i][j]=step;
    		
    		visited[i][j]=true;
    		    	if(i<rooms.size()-1 && visited[i+1][j]==false)
			    		dfs(i+1,j,rooms,step+1,visited);
			    	if (i>0 && visited[i-1][j]==false)
			    		dfs(i-1,j,rooms,step+1,visited);
			    	if(j<rooms[0].size()-1 && visited[i][j+1]==false)
			    		dfs(i,j+1,rooms,step+1,visited);
			    	if(j>0 && visited[i][j-1]==false)
			    		dfs(i,j-1,rooms,step+1,visited);
			visited[i][j]=false;
    	}

    }
};


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
    	
    	if(0==rooms.size())
    		return;
    	
    	queue<pair<int,int>> bfs;
    	vector <pair<int,int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
    	
    	for (int i=0;i<rooms.size();i++)
    	{
    		for (int j=0;j<rooms[0].size();j++)
    		{
    			if(rooms[i][j]==0)
    			{
    				bfs.emplace(i,j);
    			}
    		}
    	}
    	while(!bfs.empty())
    	{
    		pair<int,int> c=bfs.front();
    		bfs.pop();

    		for (auto & dir  :directions)
    			{
    				int x=c.first+dir.first;
    				int y=c.second+dir.second;
    				if( x<0|| x>=rooms.size() || y<0 || y>=rooms[0].size() || rooms[x][y]<=rooms[c.first][c.second]+1) 
    					continue;
    				bfs.emplace(x,y);
    				rooms[x][y]=rooms[c.first][c.second]+1;
    			}
    	}
    }
};
