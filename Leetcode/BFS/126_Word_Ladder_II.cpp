#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(!dict.count(endWord)) return {};
        dict.erase(beginWord);
        dict.erase(endWord);

        unordered_map<string,int> steps{{beginWord,0}};
        unordered_map<string,vector<string>> parents;
        queue<string> q;
        q.push(beginWord);

        vector<vector<string>> ans;
        const int l=beginWord.length();
        int step=0;
        bool found=false;
        while(!q.empty() && !found)
        {
        	
        	for(int size=q.size();size>0;size--)
        	{
        		const string p=q.front();
        		q.pop();
        		string w=p;
        		for(int i=0;i<l;i++)
        		{
        			const char ch=w[i];
        			for(char j='a';j<='z';j++)
        			{
        				if(j==ch) continue;
        				w[i]=j;
        				if(w==endWord){
        					parents[w].push_back(p);
        					found=true;
        				}
        				else
        				{
        					//?
        					if(steps.count(w) )
        						{
                                    /*
        							cout<<w<<"\n";
        							cout<<j<<'\n';
        							cout<<p<<'\n';
        							cout<<parents[w].size()<<'\n';
        							cout<<steps.at(w)<<'\n';
        							cout<<step<<'\n';
        							system("pause");
                                    */
        							if (step==steps.at(w)-1)
        								parents[w].push_back(p);
        							else if(step<steps.at(w)-1)
        								{
        									parents[w].clear();
        									parents[w].push_back(p);
        								}
        							else
        								continue;
        						}
        				}
        				if(!dict.count(w)) continue;
        				dict.erase(w);
        				q.push(w);
        				steps[w]=steps.at(p)+1;
        				parents[w].push_back(p);
        			}
        			w[i]=ch;
        		}
        	}
        	++step;
        }
        if(found){
        	vector<string> curr{endWord};
        	getPaths(endWord,beginWord,parents,curr, ans);
        }
        return ans;
    }
private:
	void getPaths(const string & word, const string & beginWord,const unordered_map<string, vector<string>>& parents,
                  vector<string>& curr,
                  vector<vector<string>>& ans)
	{
		if(word==beginWord)
		{
			ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
		}
		for(const string &p :parents.at(word))
		{
			curr.push_back(p);
			getPaths(p, beginWord, parents, curr, ans);
			curr.pop_back();
		}
	}
};
