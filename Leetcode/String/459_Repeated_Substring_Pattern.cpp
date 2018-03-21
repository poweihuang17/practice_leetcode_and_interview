//Actually, there is a solution using KMP.
//I should check that out later.
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string s2=s+s;
        string s3=s2.substr(1,2*s.size()-2);

        return s3.find(s)!=string::npos? true:false;
    }
};