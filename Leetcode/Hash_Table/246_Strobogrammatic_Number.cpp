class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<int,int> table;
        table['8']='8';
        table['1']='1';
        table['6']='9';
        table['9']='6';
        table['0']='0';

        if(num.size()%2==1)
        	if (num[num.size()/2]!='8' && num[num.size()/2]!='1'  && num[num.size()/2]!='0') return false;

        for (int i=0;i<num.size()/2;i++)
        {
        	if(table.count(num[i]))
        	{
        		if(table[num[i]]!=num[num.size()-1-i])
        			return false;
        	}
        	else
        	{
        		return false;
        	}
        }

        return true;
    }
};