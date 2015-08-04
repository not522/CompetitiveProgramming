#include "game/nim.hpp"
#include "math/prime.hpp"

int main() {
  int n;
  cin >> n;
  Prime prime;
  auto v = prime.primeFactor(n);
  vector<int> u(v.size());
  for (size_t i = 0; i < v.size(); ++i) {
    while (n % v[i] == 0) {
      ++u[i];
      n /= v[i];
    }
  }
  cout << (nim(u) ? "Alice" : "Bob") << endl;
}
