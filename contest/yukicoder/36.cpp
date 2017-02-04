#include "math/prime.hpp"

int main() {
  int64_t n;
  cin >> n;
  Prime prime;
  cout << (prime.factor(n).size() >= 3u ? "YES" : "NO") << endl;
}
