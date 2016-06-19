/*
 * 这题主要是dfs+剪枝。
 * dfs： 向更大的数值去搜
 * 剪枝: 如果更大的数值的最大path已经求出来了（之前遍历过），那么直接用该数，
 * 不需要重复dfs.
 * 1y!!
 */
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
 private:
  int n_, m_;
 public:
  int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool is_legal(int x, int y, int max_x, int max_y) {
    if (x >= 0 && x < max_x && y >= 0 && y < max_y) return true;
    return false;
  }
  int dfs(int x, int y, const vector<vector<int>>& matrix, 
          vector<vector<bool>>& visit, vector<vector<int>>& max_path) { 
    int max_sub_path = 0;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dir[i][0];
      int ny = y + dir[i][1];
      if (is_legal(nx, ny, n_, m_) && 
          matrix[x][y] < matrix[nx][ny] && !visit[nx][ny]) {
        int sub_path = 0;
        if (max_path[nx][ny] != -1) {
          sub_path = max_path[nx][ny]; 
        }
        else {
          visit[nx][ny] = true;
          sub_path = dfs(nx, ny, matrix, visit, max_path);
          visit[nx][ny] = false;
        }
        max_sub_path = max(max_sub_path, sub_path);
      }
    }
    max_path[x][y] = 1 + max_sub_path;
    return 1 + max_sub_path;
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return 0;
    if (matrix[0].size() == 0) return 0;
    int n = matrix.size(), m = matrix[0].size();
    n_ = n, m_ = m;
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    vector<vector<int>> max_path(n, vector<int>(m, -1));
    int longest_path = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        visit[i][j] = true;
        int path = dfs(i, j, matrix, visit, max_path);
        visit[i][j] = false;
        longest_path = max(longest_path, path);
      }
    }
    return longest_path;
  }
};

void test() {
  vector<vector<int>> matrix1 = {{9,9,4}, {6,6,8}, {2,1,1}};
  vector<vector<int>> matrix2 = {{3,4,5}, {3,2,6}, {2,2,1}};
  Solution sol;
  int ans = sol.longestIncreasingPath(matrix1);
  assert (ans == 4);
  ans = sol.longestIncreasingPath(matrix2);
  assert (ans == 4);
  cout << "All pass.\n";
}
int main() {
  test();
  return 0;
}
