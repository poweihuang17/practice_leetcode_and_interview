//Using set could easily solve this problem.
//But is it O(n)? I don't think so.
//Using set is bad, as it just use the property of STL.
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int a, b,c;
     	a=b=c=LONG_MIN;
     	for(auto & num:nums)
     	{
     		if(num<a || num==b || num==c) continue;

     		a=num;
     		if(a>b) swap(a,b);
     		if(b>c) swap(b,c);
     	}
     	return a==LONG_MIN?(int)c:(int)a;
    }
};

//How to generalize this solution to K number?