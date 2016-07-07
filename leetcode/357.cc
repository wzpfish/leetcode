/*
n = 1, C(10, 1)*A(1, 1) - C(9, 0)*A(0, 0)
n = 2, C(10, 2)*A(2, 2) - C(9, 1)*A(1, 1)
...
n = i, C(10, i)*A(i, i) - C(9, i-1)*A(i-1, i-1)
*/
#include <iostream>

class Solution {
public:
    int easyCombination(int n, int m) {
        if (n - m < m) return easyCombination(n, n - m);
        int ans = 1;
        for (int i = n; i >= (n - m + 1); --i) {
            ans *= i;
        }
        for (int i = 1; i <= m; ++i) {
            ans /= i;
        }
        return ans;
    }

    int factorial(int n) {
        if (n == 0) return 0;
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans *= i;
        }
        return ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        n = std::min(10, n);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += easyCombination(10, i) * factorial(i) - easyCombination(9, i - 1) * factorial(i - 1);
        }
        return ans;
    }
};

void test() {
    Solution sol;
    for (int n = 0; n <= 12; ++n) {
        std::cout << sol.countNumbersWithUniqueDigits(n) << std::endl;
    }
}
int main() {
    test();
}
