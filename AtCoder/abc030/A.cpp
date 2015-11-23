#include "template.hpp"

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a * d < b * c) cout << "TAKAHASHI" << endl;
  if (a * d > b * c) cout << "AOKI" << endl;
  if (a * d == b * c) cout << "DRAW" << endl;
}
