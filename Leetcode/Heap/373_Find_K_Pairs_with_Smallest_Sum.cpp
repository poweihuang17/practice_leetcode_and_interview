#include <vector>
#include <utility>
#include<queue>
using namespace std;

class Solution {
private:
	typedef function<bool (pair<int,int> & a, pair<int,int> & )> Compare;
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size()==0 || nums2.size()==0) return vector<pair<int, int>>();
        int i=0;
        int j=0;
        Compare comparator= [](pair<int,int> & a, pair<int,int> & b){
        	return (a.first+a.second)< (b.first+b.second);
        };
        priority_queue<pair<int,int>, vector<pair<int,int>> , Compare> myheap(comparator);

        while(1)
        {
        	if (!( myheap.size()==k && (nums1[i]+nums2[j])> (myheap.top().first+myheap.top().second) ))
        	{
        		myheap.push(make_pair(nums1[i],nums2[j]));
        		if(myheap.size()>k)
        			myheap.pop();
        	}

			if(j< (nums2.size()-1))
    				j++;
    		else 
    		{
    			if(i<nums1.size()-1)
    				{
    					i++;
    					j=0;
    				}
    			else
    				break;
    		}
        		
        	

        }
        vector<pair<int,int> > ans;
        while(!myheap.empty())
        {
        	ans.push_back(myheap.top());
        	myheap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


};