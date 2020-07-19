#include "template.hpp"

int main() {
  setBoolName("YES", "NO");
  int r(in), g(in), b(in);
  (void)r;
  cout << ((g * 10 + b) % 4 == 0) << endl;
}
