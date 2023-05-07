#include "template.hpp"

uint64_t f(uint64_t i) {
  switch (i % 4) {
  case 0:
    return i;
  case 1:
    return 1;
  case 2:
    return i ^ 1;
  case 3:
    return 0;
  }
  return -1;
}

int main() {
  uint64_t a(in), b(in);
  cout << (f(a - 1) ^ f(b)) << endl;
}
