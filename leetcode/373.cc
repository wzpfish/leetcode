#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> result;
    if (nums1.size() == 0 || nums2.size() == 0) {
      return result;
    }
    auto cmp = [&nums1, &nums2](pair<int, int> left, pair<int, int> right) {
      return (nums1[left.first] + nums2[left.second]) > (nums1[right.first] + nums2[right.second]);
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    q.emplace(0, 0);
    while (!q.empty() && k-- > 0) {
      auto top = q.top();
      q.pop();
      result.emplace_back(nums1[top.first], nums2[top.second]);
      // Only push the (a + 1, b) for (a, b) to avoid dupication, except a = 0.
      // Since (0, b) can't be reached by (-1, b)
      if (top.first + 1 < nums1.size()) {
        q.emplace(top.first + 1, top.second);
      }
      if (top.first == 0 && top.second + 1 < nums2.size()) {
        q.emplace(top.first, top.second + 1);
      }
    }
    return result;
  }
};
