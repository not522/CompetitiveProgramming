#include "template.hpp"

int main() {
  int a(in), b(in);
  if (a == 1) {
    a = 14;
  }
  if (b == 1) {
    b = 14;
  }
  cout << (a > b ? "Alice" : a < b ? "Bob" : "Draw") << endl;
}
