#include "math/prime.hpp"

int main() {
  Prime prime;
  int64_t m(in), p = 1;
  if (m != 1) {
    p = prime.factor(m)[0];
  }
  cout << p << " " << m / p << endl;
}
