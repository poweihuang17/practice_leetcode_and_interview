class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        typedef pair<int,int> Event;
        vector<Event> es;
        hs_.clear();

        for(const auto &b:buildings)
        {
        	es.emplace_back(b[0],b[2]);
        	es.emplace_back(b[1],-b[2]);
        }

        sort(es.begin(),es.end(),[](const Event& e1, const Event& e2){
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });

        vector<pair<int,int>> ans;

        for(const auto & e:es)
        {
        	int x=e.first;
        	bool entering=e.second>0;
        	int h=abs(e.second);

        	if(entering)
        	{
        		if(h>this->maxHeight())
        			ans.emplace_back(x,h);
        		hs_.insert(h);
        	}
        	else
        	{
        		hs_.erase(hs_.equal_range(h).first);
        		if(h>this->maxHeight())
        			ans.emplace_back(x,this->maxHeight());
        	}
        }
        return ans;

    }
private:
	int maxHeight() const{
		if(hs_.empty()) return 0;
		return *hs_.rbegin();
	}
	multiset<int> hs_;
};