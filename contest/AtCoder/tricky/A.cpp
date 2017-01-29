#include "template.hpp"

void solve() {
  long long a, b;
  scanf("%lld %lld", &a, &b);
  if (a == numeric_limits<long long>::min() && b == -1) puts("9223372036854775808");
  else printf("%lld\n", a / b);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) solve();
}
