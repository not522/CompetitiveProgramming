#include "template.hpp"

int main() {
  int l(in), h(in), n(in);
  for (int i = 0; i < n; ++i) {
    int a(in);
    cout << (a < l ? l - a : a <= h ? 0 : -1) << endl;
  }
}
