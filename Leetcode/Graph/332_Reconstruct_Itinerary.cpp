//Only deque could be sort?
//When to use deque? When to use queue?
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto & pair : tickets)
        	trip[pair.first].push_back(pair.second);
        for(auto & pair: trip)
        {
        	auto & dests=pair.second;
        	std::sort(dests.begin(),dests.end());
        }

        const string start="JFK";

        visit(start);

        return vector<string>(route.crbegin(),route.crend());
    }

private:
	unordered_map<string, deque<string>> trip;
	vector<string> route;

	//Postorder traversal
	void visit(const string & src)
	{
		auto & dests= trip[src];
		while(!dests.empty())
		{
			const string dest= dests.front();
			dests.pop_front();
			visit(dest);
		}
    route.push_back(src);
	}

	
};