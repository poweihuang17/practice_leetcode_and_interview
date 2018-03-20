class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
    	
    	int res=0;

        for(int i=0;i<points.size();i++)
        {
        	unordered_map<int,int> count;
        	for(int j=0;j<points.size();j++)
        	{
        		if(i==j)
        			continue;
        		int d=getDistance(points[i],points[j]);
        		count[d]++;
        	}
        	for(auto & p:count)
        		res+=p.second*(p.second-1);
        }

    	return res;
    }

private:
	int getDistance(pair<int,int> & a, pair<int,int> & b){
		int dx=a.first-b.first;
		int dy=a.second-b.second;

		return dx*dx+dy*dy;

	}
};