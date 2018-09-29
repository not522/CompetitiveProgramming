#include "template.hpp"

int main() {
  string s;
  cin >> s;
  if (s[0] == '0' || s.back() == '1') {
    cout << -1 << endl;
    return 0;
  }
  int n = s.size(), a = 1, b = n;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[n - 2 - i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == '0') {
      cout << a << " " << b << endl;
      --b;
    } else {
      cout << a << " " << a + 1 << endl;
      ++a;
    }
  }
}
