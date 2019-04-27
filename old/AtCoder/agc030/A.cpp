#include "template.hpp"

int main() {
  int64_t a, b, c;
  cin >> a >> b >> c;
  cout << b + min(a + b + 1, c) << endl;
}
