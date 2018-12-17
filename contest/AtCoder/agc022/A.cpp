#include "vector.hpp"

int main() {
  string s;
  cin >> s;
  if (s == "zyxwvutsrqponmlkjihgfedcba") {
    cout << -1 << endl;
    return 0;
  }
  if (s.size() == 26u) {
    while (s[s.size() - 2] > s.back()) s.pop_back();
    s.pop_back();
    cout << s.substr(0, s.size() - 1);
    for (char c = s.back() + 1; ; ++c) {
      if (!in(s, c)) {
        cout << c << endl;
        return 0;
      }
    }
  } else {
    cout << s;
    for (char c = 'a'; ; ++c) {
      if (!in(s, c)) {
        cout << c << endl;
        return 0;
      }
    }
  }
}
