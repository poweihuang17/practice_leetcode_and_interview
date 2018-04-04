class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1,0);
        ret[0]=1;
        for(int i=1;i<rowIndex+1;i++)
        	for(int j=i;j>=1;j--)
        		ret[j]+=ret[j-1];
        return ret;
    }
};