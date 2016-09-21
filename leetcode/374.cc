/*
 * Two notes:
 * 1. left + right may larger than int.
 * 2. At the end of the loop, we should re-calculate mid.
 */
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    long long int left = 1, right = n;
    while (left < right) {
      mid = (left + right + 1) >> 1;
      if (guess(mid) == 0) break;
      if (guess(mid) == -1) right = mid - 1;
      if (guess(mid) == 1) left = mid;
    }
    mid = (left + right + 1) >> 1;
    return mid;
  }
};
