class Solution {
public:
    bool canCross(vector<int>& stones) {
        //Map
        unordered_map<int,unordered_set<int>> steps={{0, {0}}};
        //Set to check
        unordered_set<int> c(stones.begin(),stones.end());
        //1 3 4 5 7 12
        // 1 (2,3,4)
            //for 2
            //1+1,2+1,3+1
            //2,3,4 stone

            //for 3
            //1+2, 1+3, 1+4
            //
        for(int  & pos:stones)
        {
        	unordered_set<int> & s=steps[pos];
        	for(auto it=s.begin();it!=s.end();it++)
        	{
        		if(*it-1 && c.count(pos+*it-1)) {steps[pos+*it-1].insert(*it-1); }
        		if(c.count(pos+*it))steps[pos+*it].insert(*it);
        		if(c.count(pos+*it+1))steps[pos+*it+1].insert(*it+1);
        	}
        }
        return steps[stones.back()].size();
    }
};