class Solution {
public:
    int numJewelsInStones(string J, string S) {
    	unordered_map<char,bool> table;
        for(int i=0;i<J.size();i++)
        	table[J[i]]=true;
        int count=0;
        for(int i=0;i<S.size();i++)
        	if(table.count(S[i]))
        		count++;
        return count;
    }
};