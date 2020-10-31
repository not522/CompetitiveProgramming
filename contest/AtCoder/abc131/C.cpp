#include "math.hpp"

int64_t count(int64_t a, int64_t c, int64_t d) {
  return a - a / c - a / d + a / lcm(c, d);
}

int main() {
  int64_t a(in), b(in), c(in), d(in);
  cout << count(b, c, d) - count(a - 1, c, d) << endl;
}
