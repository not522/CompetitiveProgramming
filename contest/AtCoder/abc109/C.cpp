#include "math/basic.hpp"

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> y(n);
  cin >> y;
  for (int& i : y) i -= x;
  cout << gcd(y) << endl;
}
