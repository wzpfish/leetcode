/*
 * 感觉又是练习标准库的题...
 */
#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
#include <map>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
        return x.second < y.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_to_count;   
        for (auto x: nums) {
            num_to_count[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto it = num_to_count.begin(); it != num_to_count.end(); ++it) {
            pq.push(make_pair(it->first, it->second));
        }
        
        vector<int> result;
        while (k--) {
            auto num = pq.top().first;
            pq.pop();
            result.push_back(num);
        }
        return result;
    }
};

void test() {
    Solution sol;
    vector<int> nums{1, 1, 1, 2, 2, 3};
    auto topk = sol.topKFrequent(nums, 2);
    for (auto it: topk) {
        cout << it << endl;
    }
    assert(topk == (vector<int>{1, 2}));
    cout << "All Pass." << endl;
}

int main() {
    test();
}
