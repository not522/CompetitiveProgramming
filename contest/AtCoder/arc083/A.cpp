#include "minmax.hpp"

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  a *= 100;
  b *= 100;
  double mx = -1;
  int mx_a = 0, mx_b = 0;
  for (int i = 0; i <= f; i += a) {
    for (int j = 0; i + j <= f; j += b) {
      if (i + j == 0) continue;
      for (int k = 0; i + j + k <= f; k += c) {
        for (int l = 0; i + j + k + l <= f; l += d) {
          if (100 * (k + l) > (i + j) * e) break;
          if (chmax(mx, 100.0 * (k + l) / (i + j + k + l))) {
            mx_a = i + j + k + l;
            mx_b = k + l;
          }
        }
      }
    }
  }
  cout << mx_a << " " << mx_b << endl;
}
