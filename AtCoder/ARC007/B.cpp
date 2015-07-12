#include "template.hpp"

int main() {
  int n, m, p = 0;
  cin >> n >> m;
  vector<int> v(n + 1);
  iota(v.begin(), v.end(), 0);
  for (int i = 0; i < m; ++i) {
    int d;
    cin >> d;
    swap(v[p], v[d]);
    p = d;
  }
  vector<int> res(n);
  for (int i = 0; i < n + 1; ++i) {
    if (v[i] != 0) res[v[i] - 1] = i;
  }
  for (int i : res) cout << i << endl;
}
