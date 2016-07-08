#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
 public:
  vector<int> FindMaxK(const vector<int>& nums, int k) {
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i])
    }
  }
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> result(k, -1);
    for (int i = 0; i <= k; ++i) {
      auto r1 = FindMaxK(nums1, i);
      auto r2 = FindMaxK(nums2, k - i);
      auto candidate = Merge(r1, r2);
      if (result < candidate) {
        candidate =  result;
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
