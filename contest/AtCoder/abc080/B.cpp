#include "template.hpp"

int main() {
  int n, x = 0;
  cin >> n;
  for (int m = n; m; m /= 10) x += m % 10;
  cout << (n % x == 0 ? "Yes" : "No") << endl;
}
