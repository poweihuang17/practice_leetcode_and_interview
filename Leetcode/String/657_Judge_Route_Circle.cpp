class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0;
        int j=0;
        for(auto & s:moves)
        {
        	if(s=='U')
        		i++;
        	else if (s=='D')
        		i--;
        	else if (s=='L')
        		j++;
        	else
        		j--;
        }
        return i==0? (j==0? true: false) :false;
    }
};