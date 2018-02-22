#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n=flowers.size();
        if(n==0 || k>=n) return -1;

        set<int> xs;
    	for (int i=0;i<n;i++)
    	{
    		int x=flowers[i];
    		auto r=xs.insert(x).first;
    		auto l=r;
    		if (++r!=xs.end() && *r == x+k+1) return i+1;
    		if (l!=xs.begin() && *(--l)==x-k-1) return i+1;
    	}

    	return -1;
    }
};

class Solution2 {
public:
	int kEmptySlots(vector<int>& flowers, int k){
		int n=flowers.size();
		if (n==0 || k>n) return -1;
		++k;
		int bs=(n+k-1)/k;
		vector<int> lows(bs, INT_MAX);
		vector<int> highs(bs,INT_MIN);
		for (int i=0;i<n;i++){
			int x=flowers[i];
			int p=x/k;
			if (x<lows[p]){
				lows[p]=x;
				if(p>0 && highs[p-1]==x-k) return i+1;
			}
			if (x>highs[p]){
				highs[p]=x;
				if(p< bs-1 && lows[p+1]==x+k) return i+1;
			}
		}
		return -1;
	}	
};

int main()
{
	Solution s1;
	Solution2 s2;
}