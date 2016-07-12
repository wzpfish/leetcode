/*
 * The naive solution is to simulate every burst with complexity n!, which
 * obviously TLE.
 * How can we sovle this by divide-and-conquer? 
 * At the first time I try to traverse every balloon as first to burst, but 
 * if I do this, the next balloon's burst value is depend on this, so can't
 * divide to independent subproblems.
 *
 * However, if we consider every balloon as the last to burst, problem is easy
 * to divide into subproblems. Think about it.
 *
 * See:
 * https://discuss.leetcode.com/topic/30746/share-some-analysis-and-explanations
 */

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int dp[505][505] = {0};
    int n = nums.size();
    for (int len = 3; len <= n; ++len) {
      for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1;
        for (int i = l + 1; i < r; ++i) {
          dp[l][r] = max(dp[l][r], nums[l] * nums[i] * nums[r] + dp[l][i] + dp[i][r]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
