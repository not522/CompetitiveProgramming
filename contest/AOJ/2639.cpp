#include "template.hpp"

int main() {
  int a, b, c, t = 0;
  cin >> a >> b >> c;
  for (int i = 0; t < 3600; ++i) {
    if (t % 60 <= c && c <= t % 60 + a) {
      cout << t + c - t % 60 << endl;
      return 0;
    }
    t += a + b;
  }
  cout << -1 << endl;
}
