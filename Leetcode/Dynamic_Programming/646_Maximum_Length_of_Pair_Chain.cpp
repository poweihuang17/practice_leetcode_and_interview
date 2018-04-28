class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        if (pairs.size() == 0)
            return 0;
        
        auto compare=[](const vector<int> & a, const vector<int> b)
        {
            return a[1]<b[1];
        };
        sort(pairs.begin(),pairs.end(),compare);
        
        int down=INT_MIN;
        int n=0;
        
        for(int i=0;i<pairs.size();i++)
        {
            if(pairs[i][0]>down)
            {
                down=pairs[i][1];
                n++;
            }
        }
        return n;
    }
};