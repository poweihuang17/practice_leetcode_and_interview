class Solution {
public:
//How to guarantee that this will terminate?
int getSum(int a, int b) {
    return b==0? a:getSum(a^b, (a&b)<<1);} 
};