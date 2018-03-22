#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
    	int indexAns=0, index=0;
    	while(index<chars.size())
    	{
    		char currentChar=chars[index];
    		int count=0;
    		while(index<chars.size() && chars[index]==currentChar)
    		{
    			index++;
    			count++;
    		}
    		chars[indexAns++]=currentChar;
    		if(count!=1)
    		{
    			for(auto & r: to_string(count))
    			{
    				chars[indexAns++]=r;
    			}
    		}
    	}
    	return indexAns;
    }
};

int main()
{
	vector<char> c={'a','a','b','b','c','c','c'};
	cout<<Solution().compress(c)<<'\n';
		for(auto & y:c)
		cout<<y<<' ';
	cout<<endl;
	c={'a'};
	cout<<Solution().compress(c)<<'\n';
		for(auto & y:c)
		cout<<y<<' ';
	cout<<endl;
	c={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	cout<<Solution().compress(c)<<'\n';
	for(auto & y:c)
		cout<<y<<' ';
	cout<<endl;
	c={'a','a','a','b','b','a','a'};
	cout<<Solution().compress(c)<<'\n';
	for(auto & y:c)
		cout<<y<<' ';
	cout<<endl;
}