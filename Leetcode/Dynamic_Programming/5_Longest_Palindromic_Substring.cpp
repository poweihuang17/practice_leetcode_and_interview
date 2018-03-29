class Solution {
public:
    string longestPalindrome(string  s) {
		counter=0;
        for(int i=0;i<s.size();i++)
        {
            extend_odd(s,i);
            extend_even(s,i);
        }
        return ret;
    }
    void extend_odd(string  & s, int i)
    {
        int k=0;
        while(i-k>=0 && i+k<s.size() && s[i+k]==s[i-k])
        {  
            if( (2*k+1) >ret.size())
            	ret=s.substr(i-k,2*k+1);
            k++;
        }
    }
    
    void extend_even(string  & s, int i)
    {
        int k=0;
        while(i+k+1<s.size() && i-k>=0 && s[i+k+1]==s[i-k])
        {
            if( (2*k+2) >ret.size())
            	ret=s.substr(i-k,2*k+2);
            k++;
        }
    }

private:
        int counter;
        string ret;    
};