#include "math/prime.hpp"

int main() {
  long long n;
  cin >> n;
  Prime prime;
  cout << (prime.factor(n).size() >= 3u ? "YES" : "NO") << endl;
}
