/*
 * The key idea is the same as LIS, since % operation is transitive.
 */

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> subset;
    vector<int> pre(nums.size(), -1);
    vector<int> dp(nums.size(), 1);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            pre[i] = j;
          }
        }
      }
    }
    int max_idx = -1, max_length = 0;
    for (int i = 0; i < dp.size(); ++i) {
      if (dp[i] > max_length) {
        max_length = dp[i];
        max_idx = i;
      }
    }
    while (max_idx != -1) {
      subset.push_back(nums[max_idx]);
      max_idx = pre[max_idx];
    }
    reverse(subset.begin(), subset.end());
    return subset;
  }
};
