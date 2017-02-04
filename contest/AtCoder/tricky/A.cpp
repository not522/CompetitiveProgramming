#include "template.hpp"

void solve() {
  int64_t a, b;
  cin >> a >> b;
  if (a == numeric_limits<int64_t>::min() && b == -1) cout << "9223372036854775808" << endl;
  else cout << a / b << endl;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) solve();
}
