class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> games;
        int sum=0;
        for(int i=0;i<ops.size();i++)
        {
        	if(ops[i]=="C")
        	{
        		sum-=games.top();
        		games.pop();
        	}
        	else if (ops[i]=="D")
        	{
        		sum+=2*games.top();
        		games.push(2*games.top());
        	}
        	else if(ops[i]=="+")
        	{
        		int x=games.top();
        		games.pop();
        		int y=x+games.top();
        		sum+=y;
        		games.push(x);
        		games.push(y);
        	}
        	else
        	{
        		int x=stoi(ops[i]);
        		games.push(x);
        		sum+=x;
        	}
        }
        return sum;
    }
};