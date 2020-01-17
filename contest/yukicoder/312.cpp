#include "math/prime.hpp"
#include "vector.hpp"

int main() {
  int64_t n(in);
  auto d = Prime().divisor(n);
  cout << d[d.lower_bound(int64_t(3))] << endl;
}
