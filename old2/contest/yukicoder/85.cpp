#include "template.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in), m(in), c(in);
  (void)c;
  cout << (n * m % 2 == 0 && (n != 1 || m <= 2) && (n <= 2 || m != 1)) << endl;
}
