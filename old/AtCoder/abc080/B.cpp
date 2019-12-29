#include "template.hpp"

int main() {
  int n(in), x = 0;
  for (int m = n; m; m /= 10) {
    x += m % 10;
  }
  cout << (n % x == 0) << endl;
}
