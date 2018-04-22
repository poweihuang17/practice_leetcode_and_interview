class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        /*
        vector<int> total;
        for(auto & front:fronts)
            total.push_back(front);
        for(auto & back:backs)
            total.push_back(back);
        sort(total.begin(),total.end());
        for(int i=0;i<total.size();i++)
        {
            if(i+1<total.size() && total[i+1]==total[i])
                continue;
            for(int j=0;j<total.size();j++)
        }
        */
        map<int,int> count;
        for(int i=0;i<fronts.size();i++)
        {
            if(count.count(fronts[i])==0)
                count[fronts[i]]=0;
            
            if(count.count(backs[i])==0)
                count[backs[i]]=0;
            
            if(fronts[i]==backs[i])
                count[fronts[i]]+=1;
        }
        for(auto & kv:count)
        {
            if(kv.second!=0)
                continue;
            else
                return kv.first;
        }
        return 0;
    }
};