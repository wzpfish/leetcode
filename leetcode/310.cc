/*
 * My solution is to find the longest path of the tree and the result is the
 * middle nodes of the path.
 */
class Solution {
 public:
  int FindMaxPath(int v, const vector<vector<int>>& adj_edges,
                  vector<int>& parent) {
    queue<int> q;
    vector<bool> visit(adj_edges.size(), false);
    vector<int> depth(adj_edges.size(), 0);
    q.push(v);
    visit[v] = true;
    int result = 0;
    while (!q.empty()) {
      int top = q.front();
      result = top;
      q.pop();
      for (int i = 0; i < adj_edges[top].size(); ++i) {
        int next = adj_edges[top][i];
        if (!visit[next]) {
          q.push(next);
          visit[next] = true;
          parent[next] = top;
          depth[next] = depth[top] + 1;
        }
      }
    }
    return result;
  }

  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj_edges(n);
    for (auto x : edges) {
      adj_edges[x.first].push_back(x.second);
      adj_edges[x.second].push_back(x.first);
    }
    vector<int> parent(n, -1);
    int v = FindMaxPath(0, adj_edges, parent);
    fill(parent.begin(), parent.end(), -1);
    int u = FindMaxPath(v, adj_edges, parent);
    vector<int> path;
    while (u != -1) {
      path.push_back(u);
      u = parent[u];
    }
    if (path.size() & 1) {
      return vector<int>{path[path.size() >> 1]};
    }
    else {
      return vector<int>{path[(path.size() >> 1) - 1], path[path.size() >> 1]};
    }
  }
};
