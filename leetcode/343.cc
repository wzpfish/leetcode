/*
 * 尽可能的拆成3，需要注意的是2,3,4这三个特殊情况.
 */
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int num_of_three = n / 3;
        int mod = n % 3;
        if (mod == 0) {
            return pow(3, num_of_three);
        }
        if (mod == 1) {
            return pow(3, num_of_three - 1) * 4;
        }
        return pow(3, num_of_three) * mod;
    }
};
