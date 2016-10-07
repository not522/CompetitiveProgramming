#include "template.hpp"

int main() {
  double a, b, x, y;
  cin >> a >> b >> x >> y;
  cout << min(x / a, y / b) * (a + b) << endl;
}
