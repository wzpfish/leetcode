/*
 * 想到了n & n-1 没想到0xAAAAAAAA...
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0 && (num & (num - 1)) == 0 && (num & 0xAAAAAAAA) == 0);
    }
};
