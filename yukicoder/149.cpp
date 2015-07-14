#include "template.hpp"

int main() {
  int aw, ab, bw, bb, c, d;
  cin >> aw >> ab >> bw >> bb >> c >> d;
  c -= min(ab, c);
  cout << aw - c + min(bw + c, d) << endl;
}
