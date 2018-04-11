class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(auto & token:tokens)
        {
        	if(token=="+")
        	{
        		int n1=numbers.top();
        		numbers.pop();
        		int n2=numbers.top();
                numbers.pop();
        		numbers.push(n1+n2);
        	}
        	else if(token=="-")
        	{
        		int n1=numbers.top();
        		numbers.pop();
        		int n2=numbers.top();
                numbers.pop();
        		numbers.push(n2-n1);
        	}
        	else if(token=="*" )
        	{
        		int n1=numbers.top();
        		numbers.pop();
        		int n2=numbers.top();
                numbers.pop();
        		numbers.push(n1*n2);
        	}
        	else if(token=="/")
        	{
        		int n1=numbers.top();
        		numbers.pop();
        		int n2=numbers.top();
                numbers.pop();
        		numbers.push(n2/n1);
        	}
        	else
        		numbers.push(stoi(token));
        }

        return numbers.top();
    }
};