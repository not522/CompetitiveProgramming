#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  cout << n * (n + 1) * (2 * n + 1) / 6 % m << endl;
}
