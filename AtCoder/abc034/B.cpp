#include "template.hpp"

int main() {
  int n;
  cin >> n;
  cout << n + (n % 2 ? 1 : -1) << endl;
}
