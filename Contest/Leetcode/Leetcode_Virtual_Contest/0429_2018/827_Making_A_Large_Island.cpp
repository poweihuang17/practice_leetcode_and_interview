class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ret=1;
        count=1;
        vector<int> uf(m*n,0);
        vector<int> w(m*n,1);
        for(int i=0;i<m*n;i++)
        	uf[i]=i;

        for(int i=0;i<m;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		if(grid[i][j]==0)
        			continue;
        		if(i<m-1 && grid[i+1][j]==1) join(w,uf,i*n+j,(i+1)*n+j);
        		if(i>0 && grid[i-1][j]==1) join(w,uf,i*n+j,(i-1)*n+j);
        		if(j>0 && grid[i][j-1]==1) join(w,uf,i*n+j,i*n+j-1);
        		if(j<n-1 && grid[i][j+1]==1) join(w,uf,i*n+j,i*n+j+1);
        	}
        }
        ret=max(ret,count);
        vector<int> tw=w;
        vector<int> tuf=uf;

        for(int i=0;i<m;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		if(grid[i][j]==1)
        			continue;
        		prev_count=count;
                //cout<<"start"<<endl;
        		if(i<m-1 && grid[i+1][j]==1) join(w,uf,i*n+j,(i+1)*n+j);
        		if(i>0 && grid[i-1][j]==1) join(w,uf,i*n+j,(i-1)*n+j);
        		if(j>0 && grid[i][j-1]==1) join(w,uf,i*n+j,i*n+j-1);
        		if(j<n-1 && grid[i][j+1]==1) join(w,uf,i*n+j,i*n+j+1);
                //cout<<"count:"<<count<<endl;
        		ret=max(ret,count);
        		count=prev_count;
        		w=tw;
        		uf=tuf;
        	}
        }
        return ret;
    }

    void join(vector<int> & w, vector<int> & uf,int i, int j)
    {
    	int a=find(uf,i);
    	int b=find(uf,j);
    	if(a==b)
    		return;
    	else
    	{
    		if(w[a]>w[b])
    			swap(a,b);
    		w[b]+=w[a];
    		w[a]=w[b];
    		uf[a]=uf[b];
    		count=max(w[b],count);
            //cout<<count<<endl;
    		return;
    	}
    }

    int find(vector<int> & uf,int i)
    {
    	return i==uf[i]?i:find(uf,uf[i]);
    }
private:
	int count;
	int prev_count;
};