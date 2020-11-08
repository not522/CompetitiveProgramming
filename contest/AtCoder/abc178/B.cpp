#include "template.hpp"

int main() {
  int64_t a(in), b(in), c(in), d(in);
  cout << max({a * c, a * d, b * c, b * d}) << endl;
}
