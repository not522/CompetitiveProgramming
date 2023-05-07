#include "template.hpp"

int main() {
  int px(in), py(in), qx(in), qy(in);
  cout << (abs(px - qx) + abs(py - qy)) / 2.0 << endl;
}
