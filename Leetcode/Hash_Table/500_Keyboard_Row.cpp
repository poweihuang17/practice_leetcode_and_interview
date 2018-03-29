class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a="QWERTYUIOP", b="ASDFGHJKL",d="ZXCVBNM";
        unordered_map<char,int> table;
        for(auto & c:a)
        {
            table[c]=1;
            table[tolower(c)]=1;
        }
        for(auto & c:b)
        {
            table[c]=2;
            table[tolower(c)]=2;
        }
        for(auto & c :d)
        {
            table[c]=3;
            table[tolower(c)]=3;
        }
        vector<string> ret;
        for(auto & word:words)
        {
            bool test=true;
            for(auto &c:word)
                if(table[c]!=table[word[0]])
                    test=false;
            if(test==true)
                ret.push_back(word);
        }
        return ret;
    }
};