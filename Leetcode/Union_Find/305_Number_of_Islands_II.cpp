#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        //vector<int> uf(m*n,0);
        //for(int i=0;i<m*n;i++)
        //    uf[i]=i;
        unordered_map<int,int> uf; 
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> ret;
        count=0;
        
        for(auto & p:positions)
        {
            int x=p.first;
            int y=p.second;
            
            //Join
            visited[x][y]=1;
            uf[x*n+y]=x*n+y;
            count++;
            //cout<<x*m+y<<endl;
            if(x>=1 && visited[x-1][y]) join(uf,x-1,y,x,y,m,n);
            if(x<m-1 && visited[x+1][y]) join(uf,x+1,y,x,y,m,n);
            if(y>=1 && visited[x][y-1]) join(uf,x,y-1,x,y,m,n);
            if(y<n-1 && visited[x][y+1]) join(uf,x,y+1,x,y,m,n);
            
            //Count
            ret.push_back(count);
        }
        return ret;
    }
private:
    void join(unordered_map<int,int> & uf, int x,int y, int u, int v,const int m, const int n)
    {
        //cout<<"v:"<<v<<endl;
        //cout<<"u:"<<u<<endl;
        //cout<<"x:"<<v<<endl;
        //cout<<"y:"<<u<<endl;
        int a=find(uf,x,y,m,n);
        int b=find(uf,u,v,m,n);
        if(a!=b)
        {
            uf[a]=b;
            count--;
        }
    }
    
    int find(unordered_map<int,int> & uf, int x, int y,const int & m,const int & n)
    {
        int v=n*x+y;
        int t=uf[v];
        //cout<<"v:"<<v<<endl;
        //cout<<"uf:"<<uf[v]<<endl;
        return uf[v]==v?v:uf[v]=find(uf,t/n,t%n,m,n);
    }
    int count;
};

int main()
{
    int m=3;
    int n=3;
    vector<pair<int,int>> s{{0,0},{0,1},{1,2},{2,1}};
    Solution x;
    x.numIslands2(m,n,s);
}