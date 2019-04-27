#include "template.hpp"

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s.size() > 10u) cout << s[0] << s.size() - 2 << s.back() << endl;
    else cout << s << endl;
  }
}
