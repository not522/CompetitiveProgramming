#include "string.hpp"

int main() {
  String s(in);
  int n(in);
  for (int i = 0; i < n; ++i) {
    int l(in), r(in);
    reverse(s.begin() + l - 1, s.begin() + r);
  }
  cout << s << endl;
}
