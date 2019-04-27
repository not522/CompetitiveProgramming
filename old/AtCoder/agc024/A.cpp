#include "template.hpp"

int main() {
  int64_t a, b, c, k;
  cin >> a >> b >> c >> k;
  cout << (k % 2 ? -1 : 1) * (a - b) << endl;
}
