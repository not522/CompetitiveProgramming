#include "template.hpp"

int main() {
  int px, py, qx, qy;
  cin >> px >> py >> qx >> qy;
  cout << (abs(px - qx) + abs(py - qy)) / 2.0 << endl;
}
