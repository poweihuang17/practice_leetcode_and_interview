class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        // write your code here
    	int i=number/100;
    	int j=(number%100)/10;
    	int k=number%10;

    	return i+j*10+k*100;
    }
};