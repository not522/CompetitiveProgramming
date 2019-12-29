#include "template.hpp"

int main() {
  setBoolName("Possible", "Impossible");
  int a(in), b(in);
  cout << (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) << endl;
}
