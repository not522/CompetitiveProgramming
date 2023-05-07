#include "math.hpp"

int main() {
  double a(in), b(in);
  if (a < b) {
    swap(a, b);
  }
  cout << (a * a - b * b > 0 ? sqrt(a * a - b * b) : hypot(a, b)) << endl;
}
