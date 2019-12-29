#include "template.hpp"

int main() {
  int a(in), b(in), c(in), d(in);
  cout << max(min(b, d) - max(a, c), 0) << endl;
}
