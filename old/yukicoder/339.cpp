#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  int n, g = 100;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int& i : a) g = gcd(g, i);
  cout << 100 / g << endl;
}
