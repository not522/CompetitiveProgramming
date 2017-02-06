#include "vector.hpp"

int main() {
  int64_t n, a, b;
  cin >> n >> a >> b;
  vector<int64_t> s(n);
  cin >> s;
  int64_t sum = accumulate(s), mn = min(s), mx = max(s);
  if (mn == mx && s[0] != a) {
    cout << -1 << endl;
    return 0;
  }
  double p = double(b) / (mx - mn);
  cout << p << " " << a - sum * p / n << endl;
}
