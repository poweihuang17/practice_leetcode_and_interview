class Solution {
public:
    bool hasAlternatingBits(int n) {
        int m=n>>1;
        int x=m^n;
        int y=x;
        int count=0;
        while(x!=0)
        {
            count++;
            x=x&(x-1);
        }
        while(y!=0)
        {
            count--;
            y=y>>1;
        }
        return count==0;
    }
};