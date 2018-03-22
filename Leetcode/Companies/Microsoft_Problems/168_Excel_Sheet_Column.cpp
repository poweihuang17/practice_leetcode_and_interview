class Solution {
public:
    string convertToTitle(int n) {
    	string result;
        char x;
        int temp=1;
        while((n-1)>=26)
        {
        	temp=(n-1)%26;
            n=(n-temp-1)/26;
        	x='A'+(temp);
        	result+=x;
        }
        x='A'+(n-1);
        result+=x;
        reverse(result.begin(),result.end());
        return result;
    }
};