/*
 * 这题有两个关键点：
 * 1. 要想到按位来做矩阵运算,问题就可以用矩阵快速幂来求解
 * 2. 每一位的期望求和等于整个数的期望和
 */

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;


vector<vector<double>> multiply(const vector<vector<double>>& matrix1, 
                                const vector<vector<double>>& matrix2,
                                size_t size) {
  vector<vector<double>> result(size, vector<double>(size));
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      double tmp = 0;
      for (int k = 0; k < size; ++k) {
        tmp += matrix1[i][k] * matrix2[k][j]; 
      }
      result[i][j] = tmp;
    }
  }
  return result;
}

vector<vector<double>> half_power(vector<vector<double>> matrix, size_t size, int n) {
  vector<vector<double>> result = {{1, 0}, {0, 1}};
  while (n) { 
    if (n & 1) {
      result = multiply(result, matrix, 2); 
    }
    matrix = multiply(matrix, matrix, 2);
    n >>= 1;
  }
  return result;
}

int main() {
  freopen("C-small-practice.in", "r", stdin);
  freopen("C-small-practice.out", "w", stdout);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n, x, k, a, b, c;
    cin >> n >> x >> k >> a >> b >> c;

    vector<vector<double>> trans_for_zero = {{1, 0}, {a * 1.0 / 100, (b + c) * 1.0 / 100}};
    vector<vector<double>> trans_for_one = {{a * 1.0 / 100, (b + c) * 1.0 / 100}, {c * 1.0 / 100, (a + b) * 1.0 / 100}};
    trans_for_zero = half_power(trans_for_zero, 2, n);
    trans_for_one = half_power(trans_for_one, 2, n);

    double result = 0;
    // 因为是非负数，最高位肯定都是0， 不用考虑.
    for (int i = 0; i < 31; ++i) {
      int bit_of_x = (x >> i) & 1;
      int bit_of_k = (k >> i) & 1;
      auto p = (bit_of_k == 0) ? trans_for_zero : trans_for_one;
      if (bit_of_x == 0) {
        result += ((1 << i) * p[0][1]);
      }
      else {
        result += ((1 << i) * p[1][1]);
      }
    }

    printf("Case #%d: %.10lf\n", cas, result);
  }
}
