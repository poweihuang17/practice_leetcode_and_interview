class Solution {
public:
    bool isPalindrome(int A) {
        if((A!=0 && A%10==0) || A<0) return false;
	    int x=0;
	    while(A>x)
	    {
	        x=x*10+A%10;
	        A/=10;
	    }
	    return x==A || A==x/10;
    }
};