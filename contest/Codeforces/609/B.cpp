#include "template.hpp"

int main() {
  int n, m, res = 0;
  cin >> n >> m;
  map<int, int> c;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++c[a];
  }
  for (auto i : c) res += (n -= i.second) * i.second;
  cout << res << endl;
}
