#include "math.hpp"
#include "math/prime.hpp"

int main() {
  Prime prime(1000000);
  int n(in);
  Vector<int> a(n, in);
  if (gcd(a) > 1) {
    cout << "not coprime" << endl;
    return 0;
  }
  Vector<int> div(1000001);
  for (int k : a) {
    for (int p : primeFactor(k)) {
      ++div[p];
      if (div[p] == 2) {
        cout << "setwise coprime" << endl;
        return 0;
      }
    }
  }
  cout << "pairwise coprime" << endl;
}
