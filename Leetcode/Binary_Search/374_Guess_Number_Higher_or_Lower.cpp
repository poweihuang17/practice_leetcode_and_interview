// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long high=n;
        long low=1;
        long mid=low+(high-low)/2;
        int result=guess(mid);
        while(result!=0)
        {
        	if(result==1)
        		low=mid+1;
        	else if (result==-1)
        		high=mid-1;
        	mid=(low+high)/2;
        	result=guess(mid);
        }
        return mid;
    }
};