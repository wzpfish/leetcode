class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    bool visit[256] = {false};
    int l = 0, r = 0, max_length = 0;
    while (r < s.size()) {
      if (visit[s[r]]) {
        max_length = max(max_length, r - l);
        visit[s[l++]] = false;
      }
      else {
        visit[s[r++]] = true;
      }
    }
    max_length = max(max_length, r - l);
    return max_length;
  }
};
