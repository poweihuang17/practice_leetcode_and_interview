class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m=INT_MIN;
        int count=1;
        for(int i=0;i<arr.size();i++)
        {
        	m=max(m,arr[i]);
        	if(m==i && i!=arr.size()-1)
            {
                count++;
                //cout<<i;
            }
        }
        return count;
    }
};