// I think this problem would be really hard if I use dp...
//Try a backtracking problem first.

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> visited(10,false);
        vector< vector<int> > constraint(10, vector<int>(10,-1));

        constraint[1][3]=constraint[3][1]=2;
        constraint[1][7]=constraint[7][1]=4;
        constraint[7][9]=constraint[9][7]=8;
        constraint[3][9]=constraint[9][3]=6;
        constraint[1][9]=constraint[9][1]=constraint[3][7]=constraint[7][3]=5;
        constraint[2][8]=constraint[8][2]=constraint[4][6]=constraint[6][4]=5;
        int count=0;
        for(int i=1;i<10;i++)
        	{
        		visited[i]=true;
        		backtracking(visited,1,m,n,i,count,constraint);
        		visited[i]=false;
        	}
        return count;
    }

    void backtracking(vector<bool> & visited, int k, int & min, int & max, int now,int & count,vector<vector<int>> & constraint)
    {
    	if(k<=max && k>=min) count++;
        else if (k>max) return ; 

    	for(int i=1;i<10;i++)
    	{
    		if( visited[i]) continue;
    		else if( constraint[now][i]!=-1 && visited[ constraint[now][i]]==false) continue;

    		visited[i]=true;
    		backtracking(visited,k+1, min,max,i, count,constraint);
    		visited[i]=false;
    	}
    }
};
