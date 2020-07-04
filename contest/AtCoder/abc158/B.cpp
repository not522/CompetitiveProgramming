#include "template.hpp"

int main() {
  int64_t n(in), a(in), b(in);
  cout << n / (a + b) * a + min(n % (a + b), a) << endl;
}
