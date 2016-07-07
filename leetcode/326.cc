/*
 * 由于3是素数，所以(3^x) % y == 0 IFF y = 3^z
 * 对于非素数没有这个结论，比如4^5 % 2 == 0  但是2不是4的n次幂,因为2是4的因子.
 */
class Solution {
 public:
  bool isPowerOfThree(int n) {
    int max_pow_of_three = pow(3, 19);
    return (n >= 0 && max_pow_of_three % n == 0); 
  }
};
