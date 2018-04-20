#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int x=m;
        int count=1;
        int record=0;
        while(m!=0 || n!=0)
        {
            if(m%2!=n%2) record=count; 
            m>>=1;
            n>>=1;
            count++;
        }
        int y=1;
        for(int i=record+1;i<count-1;i++)
        {
            y=(y<<1)+1;
        }
        y<<=record;
        //cout<<record<<endl;
        //cout<<count<<endl;
        //cout<<y<<endl;
        return x&y;
    }
};

int main()
{
    Solution s;
    cout<<s.rangeBitwiseAnd(2,2)<<endl;
}