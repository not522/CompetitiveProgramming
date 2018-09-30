#include "template.hpp"

int main() {
  string s, t;
  cin >> s >> t;
  vector<char> p(26);
  for (int i = 0; i < int(s.size()); ++i) {
    if (p[s[i] - 'a'] != 0 && p[s[i] - 'a'] != t[i]) {
      cout << false << endl;
      return 0;
    }
    p[s[i] - 'a'] = t[i];
  }
  for (int i = 0; i < 26; ++i) {
    if (p[i] == 0) continue;
    for (int j = i + 1; j < 26; ++j) {
      if (p[i] == p[j]) {
        cout << false << endl;
        return 0;
      }
    }
  }
  cout << true << endl;
}
