#include <vector>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ret=INT_MIN;

        for(int j=0;j<m;j++)
        {
            vector <int> s(n,0);
        	for(int l=j;l<m;l++)
        	{
        		//Fix the left and right bar, need to know the height now.
        		//|---|
        		//|---|
        		for(int i=0;i<n;i++)
        		{
        			s[i]+=matrix[i][l];
        		}

        		//Find prefix sum
        		vector<int> p(n,0);
        		partial_sum(s.begin(),s.end(),p.begin());

        		//Find subarray no larger than K.
        		set<int> f;
        		f.insert(0);
        		for(auto & item:p)
        		{	
        			auto it=lower_bound(f.begin(),f.end(),item-k);
        			if(it!=f.end()) {
                        ret=max(ret,item-(*it));
                    }
                    f.insert(item);  
        		}
        	}
        }
        return ret;
    }
};