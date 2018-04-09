class Solution {
public:
    int calculate(string s) {
        int result=0;
        int num=0,sign=1;
        stack<int> nums,ops;

        for(int i=0;i<s.size();i++)
        {
        	char c=s[i];
        	if(c>='0' && c<='9')
        	{
        		num=10*num+c-'0';
        	}
        	else if(c=='+')
        	{
        		result+=num*sign;
        		num=0;
        		sign=1;
        	}
        	else if(c=='-')
        	{
        		result+=num*sign;
        		num=0;
        		sign=-1;
        	}
        	else if(c=='(')
        	{
        		nums.push(result);
        		ops.push(sign);
        		result=0;
        		sign=1;
        	}
        	else if(c==')' && ops.size())
        	{
        		result+=num*sign;
        		num=0;

        		result=result*ops.top()+nums.top();
        		nums.pop();
        		ops.pop();
        	}
        }

        result+=num*sign;
        return result;
    }
};