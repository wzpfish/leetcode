/*
 * Naive dp solution. dp[i] = max(dp[j] + 1)  for all j < i.
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

/*
 * The N*log(N) solution is to maintain an array that store the minimum last value of the LIS 
 * for every length.
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> min_value_of_len;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(min_value_of_len.begin(),
                                  min_value_of_len.end(),
                                  nums[i]);
            if (it == min_value_of_len.end()) {
                min_value_of_len.push_back(nums[i]);
            }
            else {
                *it = nums[i];
            }
        }
        return min_value_of_len.size();
    }
};
