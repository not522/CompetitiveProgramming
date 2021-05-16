#include "vector.hpp"

int64_t solve(const Vector<int64_t> &a) {
  int64_t res = 0;
  for (int i = 1; i + 1 < a.size(); ++i) {
    chmax(res, abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[0]));
  }
  Vector<Tuple<int64_t, int64_t>> b;
  for (int i = 0; i < a.size() - 1; ++i) {
    if (a[i] < a[i + 1]) {
      b.emplace_back(a[i], a[i + 1]);
    }
  }
  if (!b.empty()) {
    b.sort();
    auto t = b[0];
    for (int i = 1; i < b.size(); ++i) {
      if (t.get<0>() <= b[i].get<0>() && b[i].get<1>() <= t.get<1>()) {
        chmax(res, 2 * (b[i].get<1>() - b[i].get<0>()));
      } else {
        chmax(res, 2 * (t.get<1>() - b[i].get<0>()));
      }
      if (b[i].get<1>() > t.get<1>()) {
        t = b[i];
      }
    }
  }
  return res;
}

int main() {
  int n(in);
  Vector<int64_t> a(n, in);
  int64_t res = solve(a);
  a.reverse();
  chmax(res, solve(a));
  int64_t sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    sum += abs(a[i] - a[i + 1]);
  }
  cout << sum - res << endl;
}
