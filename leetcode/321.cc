/*
 * I try to find the global K numbers which are max but failed. 
 * The idea is to find i max numbers in nums1 and K - i max numbers in nums2 and
 * then merge. The way to find i max numbers in a array is to use stack(simulate
 * by vector in my code).
 */
#include <vector> 
#include <iostream>
#include <assert.h>
using namespace std;

void print(const vector<int>& nums) {
  for (auto x : nums) {
    cout << x << " ";
  }
  cout << endl;
}

class Solution {
 public:
  vector<int> FindMaxK(const vector<int>& nums, int k) {
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
      while (!result.empty() && nums[i] > result.back() && nums.size() - i - 1 + result.size() >= k) {
          result.pop_back();
      }
      result.push_back(nums[i]);
    }
    return vector<int>(result.begin(), result.begin() + k);
  }
  
  vector<int> Merge(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < nums1.size()  && j < nums2.size()) {
      if (vector<int>(nums1.begin() + i, nums1.end()) > vector<int>(nums2.begin() + j, nums2.end())) {
        result.push_back(nums1[i++]);
      }
      else {
        result.push_back(nums2[j++]);
      }
    }
    while (i < nums1.size()) {
      result.push_back(nums1[i++]);
    }
    while (j < nums2.size()) {
      result.push_back(nums2[j++]);
    }
    return result;
  }

  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> result(k, -1);
    for (int i = 0; i <= k; ++i) {
      if (i > nums1.size() || k - i > nums2.size())
        continue;
      auto r1 = FindMaxK(nums1, i);
      auto r2 = FindMaxK(nums2, k - i);

      auto candidate = Merge(r1, r2);
      if (result < candidate) {
        result = candidate;
      }
    }
    return result;
  }
};


void test() {
  Solution sol;
  vector<int> nums1 = {3, 4, 6, 5};
  vector<int> nums2 = {9, 1, 2, 5, 8, 3};
  int k = 6;
  auto result = sol.maxNumber(nums1, nums2, k); 
  assert ((result == vector<int>{9, 8, 4, 6, 5, 3}));

  nums1 = {6, 7};
  nums2 = {6, 0, 4};
  result = sol.maxNumber(nums1, nums2, 5);
  assert ((result == vector<int>{6, 7, 6, 0, 4}));
  
  cout << "All pass.\n";
}
int main() {
  test();  
  return 0;
}
