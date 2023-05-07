#include "game/nim.hpp"
#include "math/prime.hpp"

int main() {
  setBoolName("Alice", "Bob");
  int n(in);
  Prime prime;
  auto v = prime.primeFactor(n);
  Vector<int> u(v.size());
  for (int i = 0; i < v.size(); ++i) {
    while (n % v[i] == 0) {
      ++u[i];
      n /= v[i];
    }
  }
  cout << nim(u) << endl;
}
