#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {

    	stack<char> mystack;

        for(auto  & c :s )
        {
        	if(c=='(' || c=='[' || c=='{')
        		mystack.push(c);
        	else if (c==')')
        	{
        		if (!mystack.empty() && mystack.top()=='(')
        			mystack.pop();
        		else 
        			return false;
        	}
        	else if(c==']')
        		if(!mystack.empty() && mystack.top()=='[')
        			mystack.pop();
        		else 
        			return false;
        	else if (c=='}')
        		if(!mystack.empty() && mystack.top()=='{')
        			mystack.pop();
        		else
        			return false;
        }

        return mystack.empty();

    }
};