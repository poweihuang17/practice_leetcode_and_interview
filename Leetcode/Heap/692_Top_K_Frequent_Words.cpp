class Solution {

private:
	typedef pair<string, int> Node;
   	typedef function<bool ( const Node &, const Node &)> Compare;


public:
    vector<string> topKFrequent(vector<string>& words, int k) {

    	unordered_map<string, int> count;
    	for(const string & word: words)
    		count[word]++;
    	
    	Compare comparator= [](const Node & a, const Node & b){
    		if( a. second==b.second)
    			return a.first< b.first;

    		return a.second>b.second;
    	};

    	priority_queue<Node, vector<Node>, Compare> q(comparator);

    	for(const auto &kv : count)
    	{
    		q.push(kv);
    		if(q.size()>k) q.pop();
    	}

    	vector<string> ans;
    	while(!q.empty())
    	{
    		ans.push_back(q.top().first);
    		q.pop();
    	}

    	std::reverse(ans.begin(),ans.end());
    	return ans;

    }
};