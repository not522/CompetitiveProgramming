#include "vector.hpp"

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  cin >> h;
  vector<pair<double, int>> b(n);
  for (int i = 0; i < n; ++i) b[i] = make_pair(abs(t - h[i] * 0.006 - a), i + 1);
  cout << min(b).second << endl;
}
