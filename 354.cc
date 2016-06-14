/*
 这题看了discuss...
 先把信封按width从小到大排序，一样大的按height从大到小排序。这样问题就转换成了height的LIS..
 遇到2维的问题可以想想怎么转换为1维.
*/

class Solution {
private:
    static bool cmp(pair<int, int> x, pair<int, int> y) {
        if (x.first == y.first) {
            return x.second > y.second;
        }
        return x.first < y.first;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> min_height_of_index;
        for (size_t i = 0; i < envelopes.size(); ++i) {
            auto height = envelopes[i].second;
            auto it = lower_bound(min_height_of_index.begin(),
                                  min_height_of_index.end(),
                                  height); 
            if (it == min_height_of_index.end()) {
                min_height_of_index.push_back(height);
            }
            else *it = height;
        }
        return min_height_of_index.size();
    }
};


