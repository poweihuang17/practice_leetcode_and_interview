class Solution {
public:
    int integerBreak(int n) {
      int l=max(n,8);
      vector<int>  table(l+1,0);
      table[1]=1;
      table[2]=1;
      table[3]=2;
      table[4]=4;
      table[5]=6;
      table[6]=9;
      table[7]=12;
      for(int i=8;i<l+1;i++)
      	table[i]=table[i-3]*3;
      return n<8? table[n] :table[l];

    }
};