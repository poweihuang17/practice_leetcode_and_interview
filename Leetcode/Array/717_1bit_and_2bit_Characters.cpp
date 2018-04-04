class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i;
        int j;
        for(i=0;i<bits.size();i++)
        {
        	j=i;
        	if(bits[i]==0)
        		continue;
        	else
        		i+=1;
        }
        
        return j==bits.size()-1? true: false;
    }
};