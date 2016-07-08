/*
 * 无穷背包..简单题
 */
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (size_t i = 0; i < coins.size(); ++i) {
      for (int j = coins[i]; j <= amount; ++j) {
        if (dp[j -coins[i]] == -1) continue;
        if (dp[j] == -1) dp[j] = dp[j - coins[i]] + 1;  
        else dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
      }   
    }   
    return dp[amount];
  }
};

