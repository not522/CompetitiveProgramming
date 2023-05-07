#include "template.hpp"

int main() {
  int a(in), b(in), c(in), d(in);
  while (true) {
    c -= b;
    if (c <= 0) {
      cout << true << endl;
      break;
    }
    a -= d;
    if (a <= 0) {
      cout << false << endl;
      break;
    }
  }
}
