#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    --a;
    rotate(v.begin(), v.begin() + a, v.begin() + a + 1);
  }
  cout << v[0] << endl;
}
