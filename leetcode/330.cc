/*
 * 由于要cover所有[1, n]的数，则下一个需要的数不能超过当前最大值+1.
 * 具体来说，假设当前能cover的最大数为max_cover_value（即[1, max_cover_value]）
 * 都可以cover到。那么假如下一个number x >= max_cover_value + 1，就说明
 * [max_cover_value + 1, x - 1] 这个区间的数不能被cover到，因此我们就需要加入
 * max_cover_value + 1这个数。这时，能cover的最大数更新为max_cover_value + 
 * (max_cover_value + 1);
 * 
 * 这题没看discuss. :)
 */
class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    int need_add = 0;
    long long int max_cover_value = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int next_need = max_cover_value + 1;
      while (max_cover_value < n && nums[i] > next_need) {
        max_cover_value += next_need;
        need_add += 1;
        next_need = max_cover_value + 1;
      }
      if (max_cover_value >= n) return need_add;
      max_cover_value += nums[i];
    }
    int next_need = max_cover_value + 1;
    while (max_cover_value < n) {
      max_cover_value += next_need;
      need_add += 1;
      next_need = max_cover_value + 1;
    }
    return need_add;
  }
};
