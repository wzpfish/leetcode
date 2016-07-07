/*
 * See: https://www.quora.com/How-can-problem-D-Sums-of-sums-from-Round-E-of-the-Google-APAC-Test-2016-be-solved-for-the-large-dataset
 * 先理一下题意，就是给你一个array，如果将array的所有subarray(a[i...j])之和排序，求排序后第l大的数到第r大的数之和。
 * 题目可以转换为寻找subarray之和的第k大数以及前K大数之和。
 * 暴力肯定不行，那只能二分..
 * 先求出subarray和的最小值min和最大值max，那么就要找一个数v(min<=v<=max),
 * 使得小于等于v的subarray和有K个。对于一个数v，怎么数小于他的个数呢？
 * 先固定住subarray的左边界，右边界往右移，直到和大于v，然后左边界向右移，这个时候注意
 * 右边界只需要从当前位置移（想想就知道为什么）。移的时候顺便把subarray的和也算好。
 * 二分的找v，问题就解决了。注意二分边界以及等于的情况。
 */

#include <iostream>
#include <assert.h>
using namespace std;

const int kSize = 200005;
long long int a[kSize] = {0};
long long int sum[kSize] = {0};
long long int sum_of_sum[kSize] = {0};
long long int N, min_value, max_value;


long long int sum_l_r(int i, int j) {
  return sum[j] - sum[i - 1];
}

long long int sum_of_sum_l_r(int i, int j) {
  if (i > j) return 0;
  return sum_of_sum[j] - sum_of_sum[i - 1] - sum[i - 1] * (j - i + 1);
}

long long int sum_of_lowest_k(long long int k) {
  if (k == 0) return 0;
  --k;
  long long int left_value = min_value, right_value = max_value;
  long long int mid_value, num_less_than_mid_value;
  long long int sum_of_lowest;
  while(left_value + 1 != right_value) {
    mid_value = (left_value + right_value) >> 1;
    num_less_than_mid_value = 0;
    sum_of_lowest = 0;
    int r = 0;
    for (int l = 1; l <= N; ++l) {
      if (r > l) {
        sum_of_lowest += sum_of_sum_l_r(l, r - 1);
      }
      else r = l;
      while (r <= N && sum_l_r(l, r) < mid_value) {
        sum_of_lowest += sum_l_r(l, r);
        ++r;
      }
      num_less_than_mid_value += (r - l);
    }
    //cout << mid_value << " " << num_less_than_mid_value << "  " << sum_of_lowest << endl;
    if (num_less_than_mid_value <= k) {
      left_value = mid_value;
    } 
    else if (num_less_than_mid_value > k) {
      right_value = mid_value;
    }
  }
  return sum_of_lowest + left_value * (k + 1 - num_less_than_mid_value); 
}

int main() {
  freopen("D-large-practice.in", "r", stdin);
  freopen("D-large-practice.out", "w", stdout);
  int T, Q;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    printf("Case #%d:\n", cas);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
      sum_of_sum[i] = sum_of_sum[i - 1] + sum[i];
      min_value = min(min_value, a[i]);
      max_value = sum_of_sum[i];
    }
    long long int low, high;
    while(Q--) {
      cin >> low >> high;
      cout << sum_of_lowest_k(high) - sum_of_lowest_k(low - 1) << endl;
    }
  }
}
