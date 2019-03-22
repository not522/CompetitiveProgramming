#include "math/polynomial.hpp"

int main() {
  Polynomial<int> poly = Polynomial<int>::identity();
  for (int i = 0; i < 4; ++i) {
    poly *= Polynomial<int>(10, 1);
  }
  for (int n; n = in, !in.eof;) {
    cout << (n <= 36 ? poly[n] : 0) << endl;
  }
}
