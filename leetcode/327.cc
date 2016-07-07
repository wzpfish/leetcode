/*
 * 这题想到了要divide and conquer，分成左边，右边，和跨越中间三种情况。
 * 对于左边和右边，就是子问题，不用考虑。
 * 对于跨越中间的情况，由于我们需要遍历所有的[i, j]
 * pair，因此其实顺序是没关系的，于是可以对左边和右边的排序，这样可以优化
 * 复杂度。
 *
 * See: https://leetcode.com/discuss/79083/share-my-solution
 */
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
 public:
  using int64 = long long int;
  // [left, right)
  int divide_conquer(vector<int64>& sums, int left, int right,
                     int lower, int upper) {
    if (left + 1 >= right) {
      return 0;
    }
    int mid = (left + right) / 2; 
    int left_count = divide_conquer(sums, left, mid, lower, upper);
    int right_count = divide_conquer(sums, mid, right, lower, upper);

    int count = 0;
    int first_ge_lower = mid;
    int first_gt_upper = mid;
    vector<int> sorted;
    int j = mid;
    for (int i = left; i < mid; ++i) {
      while (first_ge_lower < right && sums[first_ge_lower] - sums[i] < lower) ++first_ge_lower;
      while (first_gt_upper < right && sums[first_gt_upper] - sums[i] <= upper) ++first_gt_upper;
      count += (first_gt_upper - first_ge_lower);
      while (j < right && sums[j] < sums[i]) sorted.push_back(sums[j++]);
      sorted.push_back(sums[i]);
    }
    for (int i = 0; i < sorted.size(); ++i) {
      sums[i + left] = sorted[i];
    }
    return count + left_count + right_count;
     
  }
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int size = nums.size();
    if (size == 0) return 0;
    vector<int64> sums(size + 1, 0);
    for (int i = 0; i < size; ++i) {
      sums[i + 1] = sums[i] + nums[i];
    }
    return divide_conquer(sums, 0, size + 1, lower, upper);
  }
};

void test() {
  Solution sol;
  vector<int> nums = {-2, 5, -1};
  int result = sol.countRangeSum(nums, -2, 2);
  assert (result == 3);

  nums = {0, 0};
  result = sol.countRangeSum(nums, 0, 0);
  assert (result == 3);
  cout << "All pass.\n";
}

int main() {
  test();
  return 0;
}
