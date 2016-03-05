#include "vector.hpp"
#include "math/basic.hpp"
#include "math/mint.hpp"
#include "math/pow.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  cin >> l;
  Mint m(2);
  sort(l);
  unique(l);
  n = l.size();
  if (n == 1) {
    cout << pow(m, l[0]) << endl;
    return 0;
  }
  int r = l[0];
  for (auto& i : l) i -= r;
  int g = l[1];
  for (int i = 2; i < n; ++i) g = gcd(g, l[i]);
  cout << pow(m, r + (g + 1) / 2) << endl;
}
