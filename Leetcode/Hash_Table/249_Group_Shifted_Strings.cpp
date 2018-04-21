//Need to find out how to use emplace back for this problem.H
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, multiset<string>> table;
        for(auto & s: strings)
        	table[transform(s)].insert(s);
        vector<vector<string>> ret;
        for(auto & kv:table)
        {
            vector<string> temp(kv.second.begin(),kv.second.end());
            ret.push_back(temp);
        }
        	
        return ret;
    }

    string transform(string  s)
    {
    	int m=s[0]-'a';
    	for(int i=0;i<s.size();i++)
    		s[i]='a'+(((s[i]-'a')+26-m)%26);
        //cout<<s<<endl;
    	return s;
    }
};