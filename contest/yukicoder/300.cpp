#include "math/prime.hpp"

int main() {
  int64_t x(in);
  auto d = Prime().primeFactor(x);
  for (auto i : d) {
    while (x % (i * i) == 0) {
      x /= i * i;
    }
  }
  cout << x << endl;
}
