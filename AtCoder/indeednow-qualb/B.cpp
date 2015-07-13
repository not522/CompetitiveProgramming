#include "template.hpp"

int main() {
  string s, t;
  cin >> s >> t;
  for (size_t i = 0; i < s.size(); ++i) {
    if (s == t) {
      cout << i << endl;
      return 0;
    }
    rotate(s.begin(), s.end() - 1, s.end());
  }
  cout << -1 << endl;
}
