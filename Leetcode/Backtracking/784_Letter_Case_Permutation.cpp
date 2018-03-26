class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if(S.size()==0) return vector<string>{""};
        else if(S.size()==1) return isalpha(S[0])?vector<string>{S, string(1,isupper(S[0])!=0? tolower(S[0]):toupper(S[0])) } :vector<string>{S};
        
        vector<string> x=letterCasePermutation(S.substr(1));
        vector<string> y;
        for(auto & n:x)
        {
        	string a=S[0]+n;
        	y.push_back(a);
            if(isalpha(a[0])!=0 && isupper(a[0])!=0 )
            {
                   a[0]=tolower(a[0]);
                   y.push_back(a);
            }
            else if (isalpha(a[0])!=0 && islower(a[0])!=0)
            {
                   a[0]=toupper(a[0]);
                   y.push_back(a);
            }
        }
        return y;
    }
};