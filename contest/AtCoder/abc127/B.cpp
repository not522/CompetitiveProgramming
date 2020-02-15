#include "template.hpp"

int main() {
  int r(in), d(in), x(in);
  for (int i = 0; i < 10; ++i) {
    x = r * x - d;
    cout << x << endl;
  }
}
