/*
 * 一开始题目理解错了,直接set了一下..其实删除的时候不能动原来的位置的..
 * 像这种维护次序的, it's straightforward to use Stack.
 * Here the string is a natural Stack to use.
 */

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> count;
    bool used[256] = {0};
    for (auto c : s) {
      count[c]++;
    }
    string result = "0";  // for convenience 
    for (auto c : s) {
      count[c]--;
      if (used[c]) continue;
      while (c < result.back() && count[result.back()] > 0) {
        used[result.back()] = false;
        result.pop_back();
      }
      result += c;
      used[c] = true;
    }
    return result.substr(1);
  }
};
