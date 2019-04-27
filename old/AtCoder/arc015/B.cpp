#include "template.hpp"

int main() {
  int n;
  cin >> n;
  int res[6] = {};
  for (int i = 0; i < n; ++i) {
    double a, b;
    cin >> a >> b;
    if (35 <= a) ++res[0];
    if (30 <= a && a < 35) ++res[1];
    if (25 <= a && a < 30) ++res[2];
    if (25 <= b) ++res[3];
    if (0 <= a && b < 0) ++res[4];
    if (a < 0) ++res[5];
  }
  for (int i = 0; i < 6; ++i) cout << res[i] << (i == 5 ? '\n' : ' ');
}
