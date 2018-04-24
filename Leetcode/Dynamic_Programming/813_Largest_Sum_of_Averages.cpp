// Author: Huahua
// Running time: 9 ms
class Solution {
public:
  double largestSumOfAverages(vector<int>& A, int K) {
    const int n = A.size();
    vector<vector<double>> dp(K + 1, vector<double>(n + 1, 0.0));
    vector<double> sums(n + 1, 0.0);
    for (int i = 1; i <= n; ++i) {
      sums[i] = sums[i - 1] + A[i - 1];
      dp[1][i] = static_cast<double>(sums[i]) / i;
    }
    
    for (int k = 2; k <= K; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j)
          dp[k][i] = max(dp[k][i], dp[k - 1][j] + (sums[i] - sums[j]) / (i - j));   
    
    return dp[K][n];
  }
};