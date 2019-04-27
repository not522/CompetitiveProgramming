#include "template.hpp"

int main() {
  int64_t a, k;
  cin >> a >> k;
  if (k == 0) {
    cout << 2000000000000ll - a << endl;
    return 0;
  }
  for (int d = 1; ; ++d) {
    a += 1 + k * a;
    if (a >= 2000000000000ll) {
      cout << d << endl;
      return 0;
    }
  }
}
