#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> x(n);
  cin >> x;
  sort(x);
  int64_t res = 0, s = 0;
  for (int i = 1; i < n; ++i) {
    s += i * (x[i] - x[i - 1]);
    res += s;
  }
  cout << res << endl;
}
