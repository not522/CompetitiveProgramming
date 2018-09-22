#include "template.hpp"

int main() {
  int a, b, k = 0;
  cin >> a >> b;
  for (int i = a; i <= b; ++i) {
    auto s = to_string(i);
    auto r = s;
    reverse(r.begin(), r.end());
    if (s == r) ++k;
  }
  cout << k << endl;
}
