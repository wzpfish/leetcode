/*
 * Two notes:
 * 1. The terminate condition and mid caculation.
 * 2. Use long long in case of num = INT_MAX, which lead 1 + num < 0.
 */

class Solution {
 public:
  bool isPerfectSquare(int num) {
    long long left = 1, right = num, mid = (left + right + 1) >> 1;
    while (left < right) {
      mid = (left + right + 1) >> 1;
      if (mid * mid < num) left = mid;
      else if (mid * mid > num) right = mid - 1;
      else break;
    }
    if (mid * mid == num) return true;
    else return false;
  }
};
