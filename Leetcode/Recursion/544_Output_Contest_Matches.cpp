class Solution {
public:
    string findContestMatch(int n) {
        vector<string> ret;
        for(int i=0;i<n;i++)
        {
        	ret.push_back(to_string(i+1));
        }
        while(n>1)
        	{
        		for(int i=0;i<n/2;i++)
        		{
        			ret[i]="("+ret[i]+","+ret[n-i-1]+")";
        		}
                n/=2;
        	}
        return ret[0];
    }
};