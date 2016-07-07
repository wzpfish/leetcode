/*
 * LIS的变形.. 
 */
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int len[3] = {INT_MAX, INT_MAX, INT_MAX};
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j <= 2; ++j) {
        if (nums[i] <= len[j]) {
          if (j == 2) return true;
          len[j] = nums[i];
          break;
        }
      }
    }
    return false;
  }
};
