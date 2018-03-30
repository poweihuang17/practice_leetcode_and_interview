class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> table;

        while(n!=1)
        {
        	string s=to_string(n);
        	int sum=0;
        	for(auto & c:s)
        	{
        		sum+=( (c-'0')*(c-'0'));
        	}
        	if(table.count(sum))
        		return false;
        	else
        		table[sum]=true;
        	n=sum;
        }
        return true;
    }
};

//Need more mathematical proof....