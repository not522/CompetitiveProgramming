#include "vector.hpp"

int main() {
  string s;
  cin >> s;
  int res = numeric_limits<int>::max();
  for (char c = 'a'; c <= 'z'; ++c) {
    string t = s;
    while (true) {
      if (kinds(t) == 1) {
        chmin(res, int(s.size() - t.size()));
        break;
      }
      string u;
      for (int i = 0; i < int(t.size() - 1); ++i) {
        if (t[i] == c || t[i + 1] == c) u += c;
        else u += s[i];
      }
      t = u;
    }
  }
  cout << res << endl;
}
