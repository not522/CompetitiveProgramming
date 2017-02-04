#include "vector.hpp"

int main() {
  int64_t n, k, m, r;
  cin >> n >> k >> m >> r;
  vector<int64_t> s(n - 1);
  cin >> s;
  s.emplace_back(0);
  rsort(s);
  if (accumulate(s.begin(), s.begin() + k, 0ll) >= k * r) {
    cout << 0 << endl;
    return 0;
  }
  int64_t res = k * r - accumulate(s.begin(), s.begin() + k - 1, 0ll);
  cout << (res <= m ? res : -1) << endl;
}
