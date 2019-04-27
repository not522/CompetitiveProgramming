#include "template.hpp"

int main() {
  string s;
  cin >> s;
  s.pop_back();
  for (; ; s.pop_back()) {
    if (s.size() % 2) continue;
    auto a = s.substr(0, s.size() / 2);
    auto b = s.substr(s.size() / 2);
    if (a == b) {
      cout << s.size() << endl;
      return 0;
    }
  }
}
