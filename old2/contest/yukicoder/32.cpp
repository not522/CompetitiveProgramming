#include "template.hpp"

int main() {
  int l(in), m(in), n(in);
  m += n / 25;
  l += m / 4;
  cout << n % 25 + m % 4 + l % 10 << endl;
}
