#include "vector.hpp"

int main() {
  long long n, k, m, r;
  cin >> n >> k >> m >> r;
  vector<long long> s(n - 1);
  cin >> s;
  s.emplace_back(0);
  rsort(s);
  if (accumulate(s.begin(), s.begin() + k, 0ll) >= k * r) {
    cout << 0 << endl;
    return 0;
  }
  long long res = k * r - accumulate(s.begin(), s.begin() + k - 1, 0ll);
  cout << (res <= m ? res : -1) << endl;
}
