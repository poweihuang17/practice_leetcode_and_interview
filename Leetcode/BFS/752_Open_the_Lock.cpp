#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
    	unordered_set<string> dead_set;
    	for(auto & deadend: deadends)
    		dead_set.insert(deadend);

        queue< pair<string, int>> myqueue;
        unordered_set<string> visited;
        if(dead_set.find("0000")==dead_set.end()) myqueue.push(make_pair("0000",0));

        unordered_map<char, char> turn;
        for(int i=0;i<9;i++)
        	turn['0'+i]='0'+i+1;
        turn['9']='0';

        unordered_map<char, char> turn2;
        for(int i=1;i<10;i++)
        	turn2['0'+i]='0'+i-1;
        turn2['0']='9';
        

        int result=INT_MAX;

        while(!myqueue.empty())
        {
        	pair<string,int> now=myqueue.front();
        	myqueue.pop();
        	if(now.second>result) continue;
        	if(visited.find(now.first)!=visited.end()) continue;
        	if(now.first==target) result=min(result, now.second);

        	for(int i=0;i<4;i++)
        	{
        		string new_one=now.first;
        		new_one[i]=turn[new_one[i]];
        		if(dead_set.find(new_one)==dead_set.end())
                {
                    if(new_one==target) 
                    {
                        result=min(result, now.second+1);
                        break;
                    }
                    myqueue.push(make_pair(new_one, now.second+1));
                }
                
        	}

        	for(int i=0;i<4;i++)
        	{
        		string new_one=now.first;
        		new_one[i]=turn2[new_one[i]];
        		if(dead_set.find(new_one)==dead_set.end())
                {
                    if(new_one==target) 
                    {
                        result=min(result, now.second+1);
                        break;
                    }
                    myqueue.push(make_pair(new_one, now.second+1));
                }
                
        	}

            visited.insert(now.first);
        	if(result!=INT_MAX) break;
        	//cout<<now.first<<endl;
        }
        return result==INT_MAX? -1: result;
    }
};

int main()
{
	vector<string> s={"0201","0101","0102","1212","2002"};
	string target="0202";
	Solution m;
	//cout<<m.openLock(s,target);

	s={"0000"};
	target="8888";
	cout<<m.openLock(s,target);
}

