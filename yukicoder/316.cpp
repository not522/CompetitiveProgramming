#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  int n, res = 0;
  vector<int64_t> a(3);
  cin >> n >> a;
  for (int i : a) res += n / i;
  for (int i = 0; i < 3; ++i) res -= n / lcm(a[i], a[(i + 1) % 3]);
  cout << res + n / lcm(a[0], a[1], a[2]) << endl;
}
