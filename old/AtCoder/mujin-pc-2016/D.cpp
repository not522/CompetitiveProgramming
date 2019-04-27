#include "binary_search.hpp"
#include "cumulative_sum_1D.hpp"
#include "container/rmq.hpp"

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<int> v1(n), v2(n);
  for (int i = 0; i < n; ++i) v1[i] = s[i] != ')' ? 1 : -1;
  for (int i = 0; i < n; ++i) v2[i] = s[i] != '(' ? 1 : -1;
  CumulativeSum1D<int> sum1(v1), sum2(v2);
  RMQ<int> rmq1(n), rmq2(n);
  for (int i = 0; i < n; ++i) rmq1.update(i, sum1.sum(0, i + 1));
  for (int i = 0; i < n; ++i) rmq2.update(i, sum2.sum(i, n));
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r; --l;
    if ((r - l) % 2 || s[l] == ')' || s[r - 1] == '(') {cout << "No" << endl; continue;}
    int k = binarySearch([&](int64_t i){return sum1.sum(l, i) <= sum2.sum(i, r);}, l, r) + 1;
    cout << ((rmq1.query(l, k) >= sum1.sum(0, l) && rmq2.query(k, r) >= sum2.sum(r, n)) ? "Yes" : "No") << endl;
  }
}
