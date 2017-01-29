#include "template.hpp"

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i <= n; ++i) {
    if (s.substr(i, n - i) == t.substr(0, n - i)) {
      cout << n + i<< endl;
      return 0;
    }
  }
}
