/*
 * BFS... 
 */
class Solution {
 public:
  bool IsValid(string s) {
    stack<char> parentheses;
    for (auto c : s) {
      if (c == '(') {
        parentheses.push(c);
      }
      if (c == ')') {
        if (!parentheses.empty() && parentheses.top() == '(')
          parentheses.pop();
        else return false;
      }
    }
    return parentheses.size() == 0;
  }

  vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    queue<string> q;
    q.push(s);
    unordered_set<string> visit;
    visit.insert(s);
    int min_remove_num = s.size();
    while (!q.empty()) {
      string top = q.front();
      q.pop();
      if (s.size() - top.size() > min_remove_num) {
        break;
      }
      if (IsValid(top)) {
        min_remove_num = s.size() - top.size();
        result.push_back(top);
      }
      for (int i = 0; i < top.size(); ++i) {
        string next = top;
        if (top[i] == '(' || top[i] == ')') {
          next.erase(i, 1);
          if (visit.count(next) == 0) {
            q.push(next);
            visit.insert(next);
          }
        }
      }
    }
    return result;
  }
};
