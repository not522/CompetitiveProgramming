#include "template.hpp"

int main() {
  int n, a, b, x = 0;
  cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) {
    string s;
    int d;
    cin >> s >> d;
    if (d < a) d = a;
    if (d > b) d = b;
    if (s == "East") x += d;
    else x -= d;
  }
  if (x == 0) cout << 0 << endl;
  else if (x > 0) cout << "East " << x << endl;
  else cout << "West " << -x << endl;
}
