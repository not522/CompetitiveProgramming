#include "template.hpp"

int main() {
  set_bool_name("YES", "NO");
  int64_t n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  for (int i = 0; i <= n - 1; ++i) {
    auto mx = d * i - c * (n - i - 1);
    auto mn = c * i - d * (n - i - 1);
    if (a + mn <= b && b <= a + mx) {
      cout << true << endl;
      return 0;
    }
  }
  cout << false << endl;
}
