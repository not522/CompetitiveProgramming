#include "string.hpp"

int main() {
  String s(in), r = s;
  r.reverse();
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != r[i]) {
      String ss = s;
      ss.insert(i, 1, r[i]);
      String rr = ss;
      rr.reverse();
      if (ss == rr) {
        cout << ss << endl;
        return 0;
      }
      r.insert(i, 1, s[i]);
      s = r;
      reverse(s.begin(), s.end());
      if (s == r) {
        cout << s << endl;
      } else {
        cout << "NA" << endl;
      }
      return 0;
    }
  }
  s.insert(s.size() / 2, 1, s[s.size() / 2]);
  cout << s << endl;
}
