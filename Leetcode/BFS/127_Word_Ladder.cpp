#include <unordered_map>
#include <string>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    	
    	vector <bool> visited(wordList.size(),false);
    	queue < tuple<string,int,vector<bool> >  > bfs;
    	
    	bfs.push(make_tuple(beginWord,1,visited));

    	while(bfs.size()>0)
    	{
    		tuple<string,int, vector<bool> > c=bfs.front();
    		bfs.pop();
    		if ((get<0>(c)==endWord)==true) return get<1>(c);

    		for(int i=0; i< wordList.size();i++)
		    	{
		    		if(visited[i]==false && difference(get<0>(c),wordList[i])==1 )
		    		{
		    			visited[i]=true;
		    			bfs.push( make_tuple(wordList[i], get<1>(c)+1, visited) );
		    		}

		    	}
    	}
    return 0;

}


private:

	int  difference(const string & a, const string & b){
		int diff=0;
		for(int i=0;i<a.size();i++)
		{
			if (a[i]!=b[i])
				diff+=1;
		}
		return diff;
	}
};

int main()
{
	Solution s=Solution();
	vector<string> c={"hot","dot","dog","lot","log","cog"};
	std::cout<<s.ladderLength("hit","cog",c);
}