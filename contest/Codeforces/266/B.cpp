#include "template.hpp"

int main() {
  int n, t;
  string s;
  cin >> n >> t >> s;
  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      if (s.substr(j, 2) == "BG") {
        swap(s[j], s[j + 1]);
        ++j;
      }
    }
  }
  cout << s << endl;
}
