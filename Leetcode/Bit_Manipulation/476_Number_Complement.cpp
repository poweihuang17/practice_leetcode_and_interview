class Solution {
public:
    int findComplement(int num) {
    	int x=num;
    	int y=0;
    	while(x!=0)
    	{
    		y=(y<<1)+1;
    		x>>=1;
    	}
        //cout<<y;
        return y^num;
    }
};