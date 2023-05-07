#include "template.hpp"

int main() {
  int a(in), b(in), k(in);
  for (int i = 0; i < k; ++i) {
    if (i % 2 == 0) {
      a /= 2;
      b += a;
    } else {
      b /= 2;
      a += b;
    }
  }
  cout << a << " " << b << endl;
}
