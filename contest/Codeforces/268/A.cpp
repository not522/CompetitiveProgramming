#include "template.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (a[i] == b[j]) ++res;
    }
  }
  cout << res << endl;
}
