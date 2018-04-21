class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
       int j=0;
       int i=0;
        for(i=0;i<abbr.size();i++)
            {
                if(abbr[i]==word[j])
                { 
                    j++;
                    continue;
                }
                if(!isdigit(abbr[i]))
                    return false;
            
                int start=i;
            
                while(start<abbr.size() && isdigit(abbr[start]))
                    start++;
                //cout<<start<<endl;
                if(start==i)
                    {j++;continue;}
                
                int number =stoi(abbr.substr(i,start-i));
                //cout<<"number"<<number<<endl;
                int k=start-i;
                j+=(number);
                i=start-1;
                int count=0;
                while(number!=0)
                {count++;number/=10;}
                //cout<<start-i<<endl;
                //cout<<count<<endl;
                if((k) !=count) return false;
            }
        if(i==abbr.size() && j==word.size()) return true;
        else return false;
    }
};