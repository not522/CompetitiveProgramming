#include "string.hpp"

int main() {
  String s(in);
  Vector<int64_t> c(s.size());
  s.reverse();
  for (int i = 0; i < s.size(); ++i) {
    c[i] = (s[i] == 'w' ? 1 : 0);
  }
  c = c.partial_sum().reverse();
  s.reverse();
  int64_t res = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'c') {
      res += c[i] * (c[i] - 1) / 2;
    }
  }
  cout << res << endl;
}
