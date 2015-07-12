#include "math/basic.hpp"

int main() {
  int n, m;
  string name, kit;
  cin >> n >> m >> name >> kit;
  int res = 0;
  for (char c = 'A'; c <= 'Z'; ++c) {
    int a = count(name.begin(), name.end(), c);
    int b = count(kit.begin(), kit.end(), c);
    if (a == 0) continue;
    if (b == 0) {
      cout << -1 << endl;
      return 0;
    }
    res = max(res, ceil(a, b));
  }
  cout << res << endl;
}
