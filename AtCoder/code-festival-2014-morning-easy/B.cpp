#include "template.hpp"

int main() {
  int n;
  cin >> n;
  --n;
  cout << (n / 20 % 2 ? 20 - n % 20 : n % 20 + 1) << endl;
}
