/*
 * 只能想到排序的方法
 */
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    vector<int> ans(nums.size());
    sort(nums.begin(), nums.end());

    int l = (nums.size() + 1) / 2;
    int r = nums.size();

    for (int i = 0; i < nums.size(); ++i) {
      ans[i] = (i & 1) == 0 ? nums[--l] : nums[--r];
    }   
    nums = ans;
  }
};

