#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<String> s(n, in);
  for (auto &i : s) {
    i += 'z' + 1;
  }
  String t;
  while (!s.empty()) {
    s.sort();
    t += s[0][0];
    s[0] = s[0].substr(1);
    if (s[0].size() == 1u) {
      s[0] = s.back();
      s.pop_back();
    }
  }
  cout << t << endl;
}
