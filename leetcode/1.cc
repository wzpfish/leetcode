class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> num_to_idx;
    for (int i = 0; i < nums.size(); ++i) {
      num_to_idx[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
      int num = target - nums[i];
      if (num_to_idx.count(num) > 0 && num_to_idx[num] != i) {
        result.push_back(i);
        result.push_back(num_to_idx[num]);
        break;
      }
    }
    return result;
  }
};
