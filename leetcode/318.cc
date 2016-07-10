/*
 * 26 chars map to 26 bits.
 */

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    vector<int> flag(words.size(), 0);
    for (size_t i = 0; i < words.size(); ++i) {
      for (auto c : words[i]) {
        flag[i] |= (1 << (c - 'a'));
      }
    }

    int max_prod = 0;
    for (int i = 0; i < flag.size(); ++i) {
      for (int j = 0; j < flag.size(); ++j) {
        if ((flag[i] & flag[j]) == 0) {
          int prod = words[i].size() * words[j].size();
          max_prod = max(max_prod, prod);
        }
      }
    }
    return max_prod;
  }
};
