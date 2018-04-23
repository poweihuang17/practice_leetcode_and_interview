class Solution {
public:
    vector<int> findPermutation(string s) {
  		int n=s.size();
  		vector<int> res(n+1);
  		for(int i=0;i<n+1;i++)
  			res[i]=i+1;
  		for(int i=0;i<n;i++)
  		{
  			if(s[i]=='D')
  			{
  				int j=i;
  				while(s[i]=='D' && i<n) i++;
  				reverse(res.begin()+j,res.begin()+i+1);
  				i--;
  			}

  		}
  		return res;      
    }
};