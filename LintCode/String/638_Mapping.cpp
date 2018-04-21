class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if the characters in s can be replaced to get t or false
     */
    bool isIsomorphic(string &s, string &t) {
        // write your code here
        unordered_map<char,char> direct, reverse;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++)
        {
            bool x=direct.count(s[i]);
            bool y= reverse.count(t[i]);
            if( !x&& !y )
                {
                    direct[s[i]]=t[i];
                    reverse[t[i]]=s[i];
                }
            else if(x==y)
                {
                    continue;
                }
            else
                return false;
        }
        return true;
    }
};