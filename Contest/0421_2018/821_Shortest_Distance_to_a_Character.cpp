class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
    	vector<int> index;
        for(int i=0;i<S.size();i++)
        	if(S[i]==C) index.push_back(i);
        
        vector<int> ret;
        int last=S.size();
        for(int i=0;i<S.size();i++)
        {
            if(S[i]==C) {ret.push_back(0);last=i;continue;}
            
        	auto it=lower_bound(index.begin(),index.end(),i);
        	int r=it!=index.end()?*it-i:S.size();	
        	if(last!=S.size() && i>=last)
        		r=min(i-last,r);
        	ret.push_back(r);
        }
        return ret;
    }	
};