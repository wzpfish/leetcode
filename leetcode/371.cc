/* 
 * Hints:
 * 1. Sum of bits a and b:   a ^ b
 * 2. Carry of bits a and b: a & b
 */
class Solution {
 public:
  int getSum(int a, int b) {
    while (b != 0) {
      int sum = a ^ b;
      int carry = a & b;
      a = sum;
      b = (carry << 1);
    }
    return a;
  }
};
