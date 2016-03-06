#include "template.hpp"

int main() {
  string s;
  cin >> s;
  string res = s.substr(s.size() - 8);
  set<char> used;
  reverse(res.begin(), res.end());
  for (int i = 0; i < 8; ++i) {
    if (used.count(res[i])) {
      for (char j = 'A'; j <= 'H'; ++j) {
        if (!used.count(j)) {
          res[i] = j;
          break;
        }
      }
    }
    used.insert(res[i]);
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
}
