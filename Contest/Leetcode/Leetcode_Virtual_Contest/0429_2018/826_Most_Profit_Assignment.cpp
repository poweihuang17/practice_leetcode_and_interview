class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> p;
        for(int i=0;i<difficulty.size();i++)
        {
            p.emplace_back(difficulty[i],profit[i]);
        }
        sort(p.begin(),p.end());
        vector<int> m(profit.size()+1,0);
        for(int i=1;i<=profit.size();i++)
        {
            m[i]=max(m[i-1],p[i-1].second);
        }
        int ret=0;
        for(auto & w:worker)
        {
            pair<int,int> u{w,INT_MAX};
            auto it=upper_bound(p.begin(),p.end(),u);
            if(it==p.begin())
                continue;
            else
            {
                int t=it-1-p.begin();
                ret+=m[t+1];
                //cout<<m[t+1]<<' ';
                //cout<<p[t].second<<' ';
                //cout<<p[t].first<<endl;
                
            }
        }
        return ret;
        
    }
};