#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @param k: The k
     * @param a: The A
     * @param b: The B
     * @return: The answer
     */
    string addition(int k, string &a, string &b) {
        // Write your code here
        	string ret;
        	int trim1;
        	for(trim1=0;trim1<a.size() && a[trim1]=='0';trim1++)
        	    ;
        	int trim2;
        	 for(trim2=0;trim2<b.size() && b[trim2]=='0';trim2++)
        	    ;
        	
        	 
        	int carry=0;
        	int i=a.size()-1;
        	int j=b.size()-1;
        
        	while(i>=trim1 || j>=trim2 || carry!=0)
        	{
        		int a1=i>=0?a[i]-'0':0;
        		int b1=j>=0?b[j]-'0':0;
        
        		int t=a1+b1+carry;
        
        		int c=(t)%k;
        		int m=(t)/k;
        		char c1='0'+c;
        		ret.push_back(c1);
        		carry=m;
        		i--;
        		j--;
        	}
        	reverse(ret.begin(),ret.end());
        	return ret;
    }
};

int main()
{
	string a="1",b="12";
	int k=3;
	cout<< calculate_k(a,b,k);
	return 0;
}