/*
 * 用递推，后面的1个数可以由前面的推出来。注意num=0边界值
 */
class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) {
            return vector<int>{0};
        }
        vector<int> num_of_one{0, 1};
        int bit_len = 2;
        for (int i = 2; i <= num; ++i) {
            if (i >= (1 << bit_len)) bit_len++;
            int pre_num = i - (1 << (bit_len - 1));
            num_of_one.push_back(num_of_one[pre_num] + 1);
        }
        return num_of_one;
    }
};

