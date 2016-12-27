#include "vector.hpp"
#include "string/to_integer.hpp"

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> aa, bb, v(n), u(n), c(n), r;
  iota(v);
  iota(u);
  bool q = false;
  for (int i = 0; i < k; ++i) {
    string a, b;
    cin >> a >> b;
    if (a == "?") q = true;
    else if (!q) swap(v[toInteger<int>(a) - 1], v[toInteger<int>(b) - 1]);
    else swap(u[toInteger<int>(a) - 1], u[toInteger<int>(b) - 1]);
  }
  cin >> c;
  for (int i = 0; i < n; ++i) {
    if (v[u[i]] != c[i] - 1) r.emplace_back(u[i] + 1);
  }
  sort(r);
  cout << r[0] << " " << r[1] << endl;
}
