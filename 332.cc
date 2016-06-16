/*
 * 由题意可以知道，from->to构成一个欧拉路。欧拉路存在条件是要么有两个点度数为奇数，要么全是偶数。
 * 如果dfs的时候stuck住了，说明肯定搜到奇数的点了，该点肯定是最后一个点。因此回溯输出即可。
 * https://leetcode.com/discuss/84659/short-ruby-python-java-c
 */
class Solution {
 public:
  void dfs(string pos, map<string, multiset<string>> &from_to, vector<string>& itineray) {
    while (targets[pos].size()) {
      string to = *from_to[pos].begin();
      from_to[pos].erase(from_to[pos].begin());
      dfs(to);
    }
    itineray.push_back(pos);
  }

  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> itineray;
    map<string, multiset<string>> from_to;
    for (int i = 0; i < tickets.size(); ++i) {
      from_to[tickets[i].first].insert(tickets[i].second);
    }
    dfs("JFK", from_to, itineray);
    reverse(itineray.begin(), itineray.end());
    return itineray;
  }
};

