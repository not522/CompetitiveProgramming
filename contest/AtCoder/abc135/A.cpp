#include "template.hpp"

int main() {
  int a(in), b(in);
  if ((a - b) % 2 == 0) {
    cout << (a + b) / 2 << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
