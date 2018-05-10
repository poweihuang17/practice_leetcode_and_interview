class Solution {
public:
    string encode(const string & s) {
       
        if(s.size()<=1) return s;
        if (m.count(s)) return m[s];

        string ret=s;
        for(int i=1;i<=s.size();i++)
        {
        	string left=s.substr(0,i);
        	string right=s.substr(i,s.size()-i);
        	string t=solve(left)+encode(right);
        	if(t.size()<ret.size()) ret=t;
        }
        m[s]=ret;
        return ret;
    }

    string solve(const string & s)
    {
    	string ret=s;
    	string second=s+s;
    	int pos=second.find(s,1);
    	if(pos>=s.size()) ;
    	else
    	{
    		string new_string=to_string(s.size() / pos)+"["+encode(s.substr(0,pos))+"]";
    		if(new_string.size()<ret.size()) ret=new_string;
    	}
    	return ret;
    }

private:
	unordered_map<string,string> m;
};