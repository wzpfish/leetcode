/*
 * All inverse count problems can use merge-sort tech.
 * Note the terminate condition of recursion and the use of `std::move`
 */

#include <map>
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
 public:
  void SortMerge(vector<pair<int, int>>& num_idx, vector<int>& result,
                 int left, int right) {
    if (left + 1 >= right) {
      return;
    }
    int mid = (left + right) >> 1;
    SortMerge(num_idx, result, left, mid);
    SortMerge(num_idx, result, mid, right);
    vector<pair<int, int>> tmp;
    int l = left, r = mid;
    while (l < mid && r < right) {
      if (num_idx[l].first <= num_idx[r].first) {
        tmp.push_back(num_idx[l]);
        result[num_idx[l].second] += r - mid;
        l++;
      }
      else {
        tmp.push_back(num_idx[r++]);
      }
    }
    while (l < mid) {
      result[num_idx[l].second] += r - mid;
      tmp.push_back(num_idx[l++]);
    }
    while (r < right) {
      tmp.push_back(num_idx[r++]);
    }
    move(tmp.begin(), tmp.end(), num_idx.begin() + left);  
  }

  vector<int> countSmaller(vector<int>& nums) {
    vector<pair<int, int>> num_idx;
    for (int i = 0; i < nums.size(); ++i) {
      num_idx.push_back(make_pair(nums[i], i));
    }
    vector<int> result(nums.size(), 0);
    SortMerge(num_idx, result, 0, nums.size());
    return result;
  }
};

void test() {
  Solution sol;
  vector<int> nums = {5, 2, 6, 1};
  auto result = sol.countSmaller(nums);
  assert((result == vector<int>{2, 1, 1, 0}));
  cout << "All pass." << endl;
}
int main() {
  test();
  return 0;
}
