#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> t(n);
  cin >> t;
  cout << lcm(t) << endl;
}
