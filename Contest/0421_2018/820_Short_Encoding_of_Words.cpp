class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string,bool> suffix;
        
        for(auto & word:words)
        {
            string s;
            for(int i=word.size()-1;i>=0;i--)
            {
                s+=word[i];
                if(i!=0)
                    suffix[s]=false;
                else if(suffix.count(s)==0)
                    suffix[s]=true;         
            }
        }
        int count=0;
        int count2=0;
        for(auto & kv:suffix)
        {
            if(kv.second==true)
            {
                count+=kv.first.size();
                count2++;
            }
        }
        return count+count2;
    }
};