#include "template.hpp"

int main() {
  int n, k, r = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    r += a;
    if (k <= r) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
