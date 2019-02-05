#include "math/prime.hpp"
#include "string/join.hpp"

int main() {
  int n;
  cin >> n;
  Prime prime;
  vector<int> p;
  for (int i = 11; int(p.size()) < n; i += 10) {
    if (prime.isPrime(i)) p.emplace_back(i);
  }
  cout << join(p) << endl;
}
