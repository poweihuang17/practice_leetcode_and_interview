#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    	
    	vector<vector<int>> table(K+2,vector<int>(n,1e9));
    	

    	for(int i=0;i<(K+1);i++)
    	{
            table[i][src]=0;
    		for(auto & flight: flights)
    		{
    			table[i+1][flight[1]]=min(table[i+1][flight[1]], table[i][flight[0]]+flight[2]);
    		}
    	}

    	return table[K+1][dst]>=1e9? -1: table[K+1][dst];
    }
};


int main()
{
	Solution s=Solution();
	vector<vector<int>> flights{{0,1,100},{1,2,100},{0,2,500}};
	cout<<s.findCheapestPrice(3, flights, 0,2,1);
}