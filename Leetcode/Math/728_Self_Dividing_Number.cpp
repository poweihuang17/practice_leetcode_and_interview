class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i=left;i<=right;i++)
        {
        	int number=i;
        	bool got=true;
        	while(number!=0)
        	{
        		int dividend=number%10;
        		if(dividend==0 || i%dividend!=0) {
        			got=false;
        			break;
        		}
        		number=number/10;  
        	}
        	if(got) ret.push_back(i);
        }
        return ret;
    }
};