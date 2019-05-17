#include "template.hpp"

int main() {
  int n(in), d(in), k(in);
  if (d < (k + 1) * k / 2 || (2 * n - k + 1) * k / 2 < d) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; k; ++i) {
    if (d <= i + (2 * n - k + 2) * (k - 1) / 2) {
      d -= i;
      --k;
      cout << i << (k ? " " : "\n");
    }
  }
}
