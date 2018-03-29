// Need to think about one more solution about DP.
class Solution {
public:
    int countSubstrings(string s) {
        counter=0;
        for(int i=0;i<s.size();i++)
        {
            extend_odd(s,i);
            extend_even(s,i);
        }
        return counter;
    }
    void extend_odd(string s, int i)
    {
        int k=0;
        while(i-k>=0 && i+k<s.size() && s[i+k]==s[i-k])
        {
            counter++;
            k++;
        }
    }
    
    void extend_even(string s, int i)
    {
        int k=0;
        while(i+k+1<s.size() && i-k>=0 && s[i+k+1]==s[i-k])
        {
            counter++;
            k++;
        }
    }

private:
        int counter;
    
};