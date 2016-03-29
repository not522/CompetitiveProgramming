#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  vector<int> a(3), b(3);
  int n;
  cin >> a >> b >> n;
  cout << (ceil(accumulate(a), 5) + ceil(accumulate(b), 10) <= n ? "YES" : "NO") << endl;
}
