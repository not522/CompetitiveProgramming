#include "math/basic.hpp"

int main() {
  int64_t n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  auto l = lcm(n, m);
  unordered_map<int64_t, char> mem;
  for (int i = 0; i < n; ++i) mem[i * (l / n)] = s[i];
  for (int i = 0; i < m; ++i) {
    int j = i * (l / m);
    if (mem.count(j) && mem[j] != t[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << endl;
}
