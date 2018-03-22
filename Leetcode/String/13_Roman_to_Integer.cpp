#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
    	unordered_map<char,int> c({ {'X',10}, {'V',5}, {'I',1}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} } );
    	int num=0;
        int i;
        for(i=0;i+1<s.size();i++)
        {
        	if(c[s[i+1]] >c[s[i]]) {
        		num+=(c[s[i+1]] -c[s[i]]);
        		i++;
        	}
        	else
        	{
        		num+=c[s[i]];
        	}
        }
        if(i!=s.size()) num+=c[s[i]];
        return num;
    }
};