#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  map<tuple<int, int>, int> k;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    k[make_tuple(a, b)] = c;
  }
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  int res = 0;
  do {
    int r = 0;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) r += k[make_tuple(v[i], v[j])];
    chmax(res, r);
  } while (next_permutation(v.begin(), v.end()));
  cout << res << endl;
}
