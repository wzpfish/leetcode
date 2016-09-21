class Solution {
 public:
  int FindKthElement(vector<int>& nums1, int l1, int r1, 
                     vector<int>& nums2, int l2, int r2, int k) {
    if (r1 - l1 > r2 - l2) return FindKthElement(nums2, l2, r2, nums1, l1, r1, k); 
    if (l1 >= r1) return nums2[k - 1]; 
    if (k == 1) return min(nums1[l1], nums2[l2]);
    int i = min(k >> 1, r1 - l1);
    int j = k - i;
    if (nums1[l1 + i - 1] > nums2[l2 + j - 1]) {
      return FindKthElement(nums1, l1, r1, nums2, l2 + j, r2, k - j); 
    }
    else {
      return FindKthElement(nums1, l1 + i, r1, nums2, l2, r2, k - i); 
    }
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int sum = FindKthElement(nums1, 0, n, nums2, 0, m, (m + n + 1) >> 1) + FindKthElement(nums1, 0, n, nums2, 0, m, (m + n + 2) >> 1);
    return sum * 1.0 / 2;
  }
};
