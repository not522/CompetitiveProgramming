#include "template.hpp"

int main() {
  int n, k, t = 0;
  cin >> n >> k;
  if ((n - 1) % (k + 1) == 0) {
    cout << 0 << endl;
    cin >> t;
  }
  while (t < n) {
    cout << t + (n - 1 - t) % (k + 1) << endl;
    cin >> t;
  }
}
