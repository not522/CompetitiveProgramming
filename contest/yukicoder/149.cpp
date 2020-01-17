#include "template.hpp"

int main() {
  int aw(in), ab(in), bw(in), bb(in), c(in), d(in);
  (void)bb;
  c -= min(ab, c);
  cout << aw - c + min(bw + c, d) << endl;
}
