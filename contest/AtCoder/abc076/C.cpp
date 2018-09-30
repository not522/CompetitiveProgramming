#include "vector.hpp"

int main() {
  string s, t;
  cin >> s >> t;
  vector<string> r;
  for (int i = 0; i <= int(s.size()) - int(t.size()); ++i) {
    bool ok = true;
    for (int j = 0; j < int(t.size()); ++j) {
      if (s[i + j] != t[j] && s[i + j] != '?') ok = false;
    }
    if (ok) {
      string a;
      for (int j = 0; j < i; ++j) a += (s[j] == '?' ? 'a' : s[j]);
      a += t;
      for (int j = i + t.size(); j < int(s.size()); ++j) a += (s[j] == '?' ? 'a' : s[j]);
      r.emplace_back(a);
    }
  }
  if (r.empty()) cout << "UNRESTORABLE" << endl;
  else cout << min(r) << endl;
}
