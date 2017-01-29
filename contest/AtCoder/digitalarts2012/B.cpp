#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int hash = 0;
  for (char c : s) hash += c - 'a' + 1;
  if (s == "a" || s == string(20, 'z')) {
    cout << "NO" << endl;
  } else if (s.substr(0, s.size() - 1) != string(s.size() - 1, 'z')) {
    if (hash % 26) cout << string(hash / 26, 'z') << (char)(hash % 26 + 'a' - 1) << endl;
    else cout << string(hash / 26, 'z') << endl;
  } else if (s.size() == 20u) {
    --s[0];
    ++s.back();
    cout << s << endl;
  } else {
    --s[0];
    cout << s << 'a' << endl;
  }
}
