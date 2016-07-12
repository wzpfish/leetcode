/*
 * The basic use of Binary Indexed Tree.
 * The key idea of BIT is: for every index in the array(begin with 1), we can
 * write the index to binary format. And the value of last bit of 1 is the
 * number of continued array elements.
 *
 * For example:
 * Given an original array A, indexed from 1...N
 * The BIT index 13 can be written as: 1101. So BIT[13] = BIT[13] + BIT[12] + BIT[8]
 * For 13, the value of last bit of 1 is 2^0=1, so BIT[13] only contains A[13]
 * For 12, the value of last bit of 1 is 2^2=4, so BIT[12] contains A[12], A[11], A[10], A[9]
 * For 8,  the value of last bit of 1 is 2^3=8, so BIT[8]  contains A[8], A[7] ... A[1]
 */

class NumArray {
 public:
  vector<int> BIT_;
  vector<int> nums_;
  int lowbit(int x) {
    return x&(-x);
  }

  NumArray(vector<int> &nums) {
    BIT_.resize(nums.size() + 1);
    nums_ = nums;
    for (int i = 1; i <= nums.size(); ++i) {
      for (int j = i; j >= i - lowbit(i) + 1; --j) {
        BIT_[i] += nums[j - 1];
      }
    }
  }

  void update(int i, int val) {
    int delta = val - nums_[i];
    nums_[i] = val;
    i = i + 1;
    for (int j = i; j < BIT_.size(); j +=lowbit(j)) {
      BIT_[j] += delta;
    }
  }

  int sum(int k) {
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i)) {
      ans += BIT_[i];
    }
    return ans;
  }

  int sumRange(int i, int j) {
    return sum(j + 1) - sum(i);    
  }
};
