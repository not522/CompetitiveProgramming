#include "template.hpp"

int main() {
  int64_t n, a, b;
  cin >> n >> a >> b;
  if (n == 1) {
    if (a == b) cout << 1 << endl;
    else cout << 0 << endl;
  } else if (a > b) {
    cout << 0 << endl;
  } else {
    cout << (n - 2) * (b - a) + 1 << endl;
  }
}
