#include "string.hpp"

int main() {
  int a(in), b(in);
  for (int i = a; i <= b; ++i) {
    if (i % 3 == 0 || String(i).contains('3')) {
      cout << i << endl;
    }
  }
}
