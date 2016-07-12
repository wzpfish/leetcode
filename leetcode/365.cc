/*
 * TLE answer.
 */
class Solution {
 public:
  bool canMeasureWater(int x, int y, int z) {
    set<pair<int, int>> visit;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visit.emplace(0, 0);
    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      cout << top.first << " " << top.second << endl;
      if (top.first == z || top.second == z) {
        return true;
      }
      vector<pair<int, int>> next_states;
      next_states.emplace_back(x, top.second);
      next_states.emplace_back(top.first, y);
      next_states.emplace_back(0, top.second);
      next_states.emplace_back(top.first, 0);
      int min_pour = min(top.first, y - top.second);
      next_states.emplace_back(top.first - min_pour, top.second + min_pour);
      min_pour = min(x - top.first, top.second);
      next_states.emplace_back(top.first + min_pour, top.second - min_pour);
      for (auto next_state : next_states) {
        if (visit.count(next_state) == 0) {
          q.push(next_state);
          visit.insert(next_state);
        }
      }
    }
    return false;
  }
};

/*
 * Accept math's answer.
 * See: http://www.math.tamu.edu/~dallen/hollywood/diehard/diehard.htm
 */
class Solution {
 public:
  int gcd(int a, int b) {
    while (b != 0) {
      int mod = a % b;
      a = b;
      b = mod;
    }
    return a;
  }

  bool canMeasureWater(int x, int y, int z) {
    if (z == 0 || x + y >= z && (z % gcd(x, y)) == 0) return true;
    return false;
  }
};
