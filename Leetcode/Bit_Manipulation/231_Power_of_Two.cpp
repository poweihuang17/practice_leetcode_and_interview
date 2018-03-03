#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        else 
        	{
        		
        		return (n&(n-1))==0;
        	}
    }
};