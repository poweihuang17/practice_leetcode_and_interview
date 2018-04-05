class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        int sum=1;
        int end=num;
        for(int i=2;i<end;i++)
        {
        	if(num%i==0) {
        		sum+=(i+num/i);
        		end=num/i;
                cout<<i;
        	}
        }
        return sum==num;

    }
};