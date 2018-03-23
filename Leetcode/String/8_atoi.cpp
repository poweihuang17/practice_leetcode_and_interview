#include <string>
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
    	long long int num=0;
        int plus=0;
        bool start=false;
        for(auto & s:str)
        {
            if(s==' ') {
                if(start==false) continue;
                else
                    break;
            }
            else if (s=='+') {
                if(plus==-1) break;
                else if(plus==1) break;
                plus=1;
                start=true;
                continue;
            }
            else if (s=='-') {
                if(plus==1) break;
                else if(plus==-1) break;
                plus=-1;
                start=true;
                continue;
            }
            else if(!isdigit(s))
                break;
            long long int temp=s-'0';
        	num=num*10+temp;
        	cout<<num<<endl;
            if(plus!=-1 && num>INT_MAX) return INT_MAX;
            else if(num*plus<INT_MIN) return INT_MIN;
            
            start=true;
        }
        return plus==0? (num>INT_MAX? INT_MAX:num): (num*plus>INT_MAX? INT_MAX: (num*plus<INT_MIN? INT_MIN:num*plus) );
    }
};

int main(){
	string a="9223372036854775809";
	cout<<Solution().myAtoi(a);
	return 0;
}