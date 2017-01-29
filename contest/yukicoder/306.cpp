#include "template.hpp"

int main() {
  double xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  cout << (xa * yb + xb * ya) / (xa + xb) << endl;
}
