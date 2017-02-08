#include "template.hpp"

int main() {
  int n, a, b, r = 0;
  cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (a <= t && t < b) ++r;
  }
  cout << n - r << endl;
}
