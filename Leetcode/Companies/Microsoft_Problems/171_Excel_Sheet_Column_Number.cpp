class Solution {
public:
    int titleToNumber(string s) {
        int num=0;
        for(auto & c:s)
        {
        	num=num*26+(c-'A'+1);
        }
        return num;
    }
};