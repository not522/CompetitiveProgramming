#include "math.hpp"

int main() {
  int x(in), y(in), r(in);
  cout << int(floor(max(abs(x - y), abs(x + y)) + r * M_SQRT2)) + 1 << endl;
}
