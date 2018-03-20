class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
      unordered_map<int,int> table;
      vector<int> ans(A.size(),0);
      for(int  i=0;i<B.size();i++)
      {
      	table[B[i]]=i;
      }  
      int j=0;
      for(auto & a:A)
      {
      	ans[j]=table[a];
        j++;
      }
      return ans;
    }
};