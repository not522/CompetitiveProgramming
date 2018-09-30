#include "minmax.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n - 1; ++i) {
    int c, s, f;
    cin >> c >> s >> f;
    for (int j = 0; j <= i; ++j) {
      for (chmax(t[j], s); t[j] % f; ++t[j]);
      t[j] += c;
    }
  }
  cout << t;
}
