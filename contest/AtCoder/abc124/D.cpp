#include "cumulative_sum_1D.hpp"
#include "string.hpp"

int main() {
  int n(in), k(in), r = 0;
  String s(in);
  Vector<int> v;
  if (s[0] == '0') {
    v.emplace_back(0);
  }
  v.emplace_back(1);
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == s[i]) {
      ++v.back();
    } else {
      v.emplace_back(1);
    }
  }
  if (s.back() == '0') {
    v.emplace_back(0);
  }
  if (v.size() <= 2 * k + 1) {
    cout << n << endl;
  } else {
    CumulativeSum1D<int> sum(v);
    for (int i = 0; i + 2 * k < v.size(); i += 2) {
      chmax(r, sum.sum(i, i + 2 * k + 1));
    }
    cout << r << endl;
  }
}
