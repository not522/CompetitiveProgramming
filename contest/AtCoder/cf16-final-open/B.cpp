#include "template.hpp"

int main() {
  int n, s = 0;
  cin >> n;
  for (int i = 0; ; ++i) {
    s += i;
    if (s < n) continue;
    for (int j = 1; j <= i; ++j) {
      if (s - n == j) continue;
      cout << j << endl;
    }
    return 0;
  }
}
