class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int res=1,cur=0;
        for(auto & c:S)
        {
        	int temp=widths[c-'a'];
        	res=cur+temp>100? res+1:res;
        	cur=cur+temp>100? temp:cur+temp;
        }
        return vector<int>{res,cur};
    }
};