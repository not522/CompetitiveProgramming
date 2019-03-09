#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  Vector<int> a(n, cin);
  cout << gcd(a) << endl;
}
