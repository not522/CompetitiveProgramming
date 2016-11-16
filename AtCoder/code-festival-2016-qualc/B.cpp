#include "vector.hpp"

int main() {
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  cin >> a;
  cout << max(2 * max(a) - k - 1, 0) << endl;
}
