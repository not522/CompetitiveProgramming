#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n), s(m);
  cin >> p >> s;
  int res = 0;
  for (int i : s) res += p[i - 1];
  cout << res << endl;
}
