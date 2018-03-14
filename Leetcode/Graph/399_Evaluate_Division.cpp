//Before we insert something in hash table, we could access it?
//table[pair.second].push_back(  make_pair(pair.second, values[count] ));
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        if(equations.size()==0) return vector<double>();
        unordered_map < string, vector<pair<string,double>>  > table;
        unordered_map < string, bool> visited;
        int count=0;
        for (auto & pair: equations)
        {

        	table[pair.first].push_back(  make_pair(pair.second, values[count] ));
        	table[pair.second].push_back(  make_pair(pair.first, 1.0/values[count] ));
        	count++;
        	if(visited.count(pair.first)==0)
        		visited[pair.first]=false;
        	if(visited.count(pair.second)==0)
        		visited[pair.second]=false;
        }

        vector<double> result;
        for(auto & pair:queries)
        {
        	string start =pair.first;
        	string end=pair.second;
        	string now=start;
        	double number=1.0;
        	if(dfs(table, now, end, number, visited)) result.push_back(number);
        	else
        		result.push_back(-1.0);
        }
        return result;
    }

    bool dfs(unordered_map<string,vector<pair<string,double>>> & table, string & now, string & end , double & number, unordered_map < string, bool> & visited){
    	if(now==end && visited.count(now))
    		return true;

    	visited[now]=true;
    	for(auto pair : table[now])
    	{
    		if(!visited[pair.first])
            {
                double temp=number*pair.second;
    			if(dfs(table, pair.first,end,temp,visited) ) 
    				{
    					visited[now]=false;
                        number=temp;
    					return true;
    				}
            }
    	}
    	visited[now]=false;
    	return false;
    }
};