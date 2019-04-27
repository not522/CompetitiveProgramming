#include "template.hpp"

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d) ? "Yes" : "No") << endl;
}
