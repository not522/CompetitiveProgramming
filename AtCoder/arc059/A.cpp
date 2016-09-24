#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  int res = numeric_limits<int>::max();
  for (int i = -100; i <= 100; ++i) {
    res = min(res, accumulate<int>(a, [&](int x, int y){return x + (i - y) * (i - y);}));
  }
  cout << res << endl;
}
