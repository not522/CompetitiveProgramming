#include "template.hpp"

int main() {
  int a(in), b(in), r = 0;
  for (int i = 0; i < 2; ++i) {
    if (a > b) {
      r += a;
      --a;
    } else {
      r += b;
      --b;
    }
  }
  cout << r << endl;
}
