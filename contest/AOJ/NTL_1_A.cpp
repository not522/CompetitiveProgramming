#include "math/prime.hpp"

int main() {
  int n(in);
  Prime prime(1000000);
  cout << n << ": ";
  prime.factor(n).output(' ');
}
