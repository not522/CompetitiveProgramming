#include "template.hpp"

int main() {
  int64_t a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << a * b % d * c % d << endl;
}
