#include "template.hpp"

int main() {
  double l, x, y, s, d;
  cin >> l >> x >> y >> s >> d;
  d = s < d ? d - s: d - s + l;
  if (x < y) cout << min(d / (x + y), (l - d) / (y - x)) << endl;
  else cout << d / (x + y) << endl;
}
