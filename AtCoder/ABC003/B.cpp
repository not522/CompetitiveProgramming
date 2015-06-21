#include "template.hpp"

int main() {
  string s, t;
  cin >> s >> t;
  string atcoder = "atcoder";
  for (int i = 0; i < int(s.size()); ++i) {
    bool ok = (s[i] == t[i]);
    if (s[i] == '@' && atcoder.find(t[i]) != string::npos) ok = true;
    if (t[i] == '@' && atcoder.find(s[i]) != string::npos) ok = true;
    if (!ok) {
      cout << "You will lose" << endl;
      return 0;
    }
  }
  cout << "You can win" << endl;
}
