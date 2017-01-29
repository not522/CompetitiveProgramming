#include "template.hpp"

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  cout << (n * m % 2 || (n == 1 && m > 2) || (n > 2 && m == 1) ? "NO" : "YES") << endl;
}
