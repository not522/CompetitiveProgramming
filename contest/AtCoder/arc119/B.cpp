#include "string.hpp"

int main() {
  int n(in);
  String s(in), t(in);
  Vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      a.emplace_back(i);
    }
    if (t[i] == '0') {
      b.emplace_back(i);
    }
  }
  if (a.size() != b.size()) {
    cout << -1 << endl;
    return 0;
  }
  int res = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      ++res;
    }
  }
  cout << res << endl;
}
