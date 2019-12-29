#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in), a = 0, b = 0;
  (void)n;
  String s(in);
  for (char c : s) {
    if (c == '(') {
      ++a;
    } else {
      --a;
      chmin(b, a);
    }
  }
  cout << String(-b, '(') << s << String(-b + s.count('(') - s.count(')'), ')')
       << endl;
}
