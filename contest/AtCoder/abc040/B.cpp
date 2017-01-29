#include "minmax.hpp"

int main() {
  int n, res = numeric_limits<int>::max();
  cin >> n;
  for (int i = 1; i <= n; ++i) chmin(res, abs(i - n / i) + n % i);
  cout << res << endl;
}
