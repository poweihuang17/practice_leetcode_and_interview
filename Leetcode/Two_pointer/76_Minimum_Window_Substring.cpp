// What's the correct meaning of end?
//Included or not included?

class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<int,int> reference;

        for(int i=0;i<t.size();i++)
        {
            reference[t[i]]++;
        }

        int left=0;
        int right=0;
        int count=reference.size();
        int length=INT_MAX;
        string ret;

        while(right<s.size())
            {
                if(reference.count(s[right]))
                {
                    reference[s[right]]--;
                    if(reference[s[right]]==0)
                        count--;
                }
                right++;

                while(count==0)
                {
                    if(reference.count(s[left]))
                    {
                        if(reference[s[left]]==0)
                            count++;
                        reference[s[left]]++;
                    }
                    
                    if( (right-left) <length)
                        {
                            ret=s.substr(left,right-left);
                            length=right-left;
                            cout<<length;
                        }
                    left++;
                }
            }
        return ret;
    }
};