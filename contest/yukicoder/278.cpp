#include "math/prime.hpp"

int main() {
  int64_t n(in);
  cout << Prime().divisor(n % 2 ? n : n / 2).accumulate() << endl;
}
