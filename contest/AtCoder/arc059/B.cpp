#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (size_t i = 0; i < s.size() - 1; ++i) {
    if (s[i] == s[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
    if (i != 0 && s[i - 1] == s[i + 1]) {
      cout << i << " " << i + 2 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
}
