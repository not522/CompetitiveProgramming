#include "math/prime.hpp"

int main() {
  setBoolName("YES", "NO");
  int64_t n(in);
  Prime prime;
  cout << (prime.factor(n).size() >= 3) << endl;
}
