/*
 * Math problem. Write the result in the unfold format and the solution is
 * obvious now.
 */
class Solution {
 public:
  int binary_pow(int a, int b) {
    int result = 1;
    while (b) {
      a %= 1337;
      if (b & 1) {
        result = result * a % 1337;
      }
      a = a * a;
      b >>= 1;
    }
    return result;
  }

  int superPow(int a, vector<int>& b) {
    int result = 1;
    for (int i = b.size() - 1; i >= 0; --i) {
      result = result * binary_pow(a, b[i]) % 1337;
      a = binary_pow(a, 10);
    }
    return result;
  }
};
