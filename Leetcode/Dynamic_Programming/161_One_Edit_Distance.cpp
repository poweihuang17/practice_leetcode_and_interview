#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h> 
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
    	int diff=s.size()-t.size();
        if(abs(diff)==0)
        {
        	bool one_distance=false;
        	for(int i=0;i<s.size();i++)
        	{
        		if(s[i]!=t[i]) 
        			{
        				if(one_distance==false)
        					one_distance=true;
        				else
        					return false;
        			}
        	}
        	return one_distance;
        }
        else if(abs( diff)==1)
        {
        	bool one_distance=false;
        	int m=s.size();
        	int n=t.size();
        	int l=min(m,n);
        	for(int i=0;i<l;i++)
        	{
        		if(s[i]!=t[i])
        		{
        			if(one_distance) return false;

        			if(s.size()<t.size())
        			{
        					s.insert(i,1,t[i]);
        					one_distance=true;
        			}
        			else
        			{
        					t.insert(i,1,s[i]);
        					one_distance=true;
        			}
        		}
        	}
        	return one_distance==false || (one_distance==true && s.back()==t.back() );
        }
        else
        	return false;
    }
};

int main()
{
	string a="";
	string b="A";
	cout<<Solution().isOneEditDistance(a,b);
}