#include "template.hpp"

int main() {
  int n(in), s = 0;
  for (int i = 0; i < n; ++i) {
    int l(in), r(in);
    s += r - l + 1;
  }
  cout << s << endl;
}
