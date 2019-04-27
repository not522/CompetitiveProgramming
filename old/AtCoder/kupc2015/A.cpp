#include "template.hpp"

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < int(s.size()) - 4; ++i) {
      if (s.substr(i, 5) == "tokyo" || s.substr(i, 5) == "kyoto") {
        i += 4;
        ++res;
      }
    }
    cout << res << endl;
  }
}
