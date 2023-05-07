#include "template.hpp"

int main() {
  int n(in), k(in);
  cout << (1 << (n - k)) - (k == 1 ? n : 0) << endl;
}
