class Solution {
public:
    int hammingDistance(int x, int y) {
      int t=x^y;
      int count=0;
      while(t!=0)
      {
      	t=t&(t-1);
      	count++;
      }  
      return count;
    }
};