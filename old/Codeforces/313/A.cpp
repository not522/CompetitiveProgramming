#include "template.hpp"

int main() {
  int n;
  cin >> n;
  cout << (n > 0 ? n : max(n / 10, n / 100 * 10 + n % 10)) << endl;
}
