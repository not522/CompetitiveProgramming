#include "template.hpp"

int main() {
  string s;
  cin >> s;
  string r = s;
  reverse(r.begin(), r.end());
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] != r[i]) {
      string ss = s;
      ss.insert(i, 1, r[i]);
      string rr = ss;
      reverse(rr.begin(), rr.end());
      if (ss == rr) {
        cout << ss << endl;
        return 0;
      }
      r.insert(i, 1, s[i]);
      s = r;
      reverse(s.begin(), s.end());
      if (s == r) cout << s << endl;
      else cout << "NA" << endl;
      return 0;
    }
  }
  s.insert(s.size() / 2, 1, s[s.size() / 2]);
  cout << s << endl;
}
