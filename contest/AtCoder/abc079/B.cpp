#include "template.hpp"

int main() {
  int64_t n, a = 2, b = 1;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    b += a;
    a = b - a;
  }
  cout << b << endl;
}
