//Use bellmen-ford, as it's super easy....
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    	const int MAX_TIME=101*100;
    	vector<int> dist(N,MAX_TIME);
    	dist[K-1]=0;

    	for(int i=1;i<N;i++)
    	{
    		for(auto & time: times)
    		{
    			int u=time[0]-1;
    			int v=time[1]-1;
    			int w=time[2];
    			dist[v]=min(dist[v], dist[u]+w);
    		}
    	}
    	int max_dist = *max_element(dist.begin(),dist.end());

    	return max_dist==MAX_TIME? -1 : max_dist;
        
    }
};