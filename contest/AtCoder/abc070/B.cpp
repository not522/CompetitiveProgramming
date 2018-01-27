#include "template.hpp"

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(min(b, d) - max(a, c), 0) << endl;
}
