#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> s(n), t(n);
  cin >> s >> t;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      cout << i + 1 << endl;
      cout << s[i] << endl;
      cout << t[i] << endl;
      return 0;
    }
  }
}
