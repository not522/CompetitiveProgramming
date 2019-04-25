#include "template.hpp"

int main() {
  int n(in), m(in);
  int a = (60 * n + m) % 720, b = 12 * m;
  cout << 0.5 * min(abs(a - b), 720 - abs(a - b)) << endl;
}
