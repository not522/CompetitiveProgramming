#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  set_bool_name("POSSIBLE", "IMPOSSIBLE");
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  cin >> a;
  int g = gcd(a);
  cout <<(k % g == 0 && k <= max(a)) << endl;
}
