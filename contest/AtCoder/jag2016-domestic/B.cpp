#include "vector.hpp"

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  vector<int> a(n), b(n + 2);
  cin >> a;
  a.insert(a.begin(), -m);
  a.emplace_back(t + m);
  adjacent_difference(a.begin(), a.end(), b.begin(), [&](int i, int j){return max(i - j - 2 * m, 0);});
  cout << accumulate(b.begin() + 1, b.end(), 0) << endl;
}
