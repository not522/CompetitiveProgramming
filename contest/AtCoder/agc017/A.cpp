#include "math/combination.hpp"

int main() {
  int n, p, o = 0;
  cin >> n >> p;
  vector<int> a(n);
  cin >> a;
  for (int i : a) o += i % 2;
  int64_t res = 0;
  Combination<int64_t> comb;
  for (int i = 0; i <= o; ++i) {
    if (i % 2 != p) continue;
    res += comb.combination(o, i) << (n - o);
  }
  cout << res << endl;
}
