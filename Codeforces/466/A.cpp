#include "template.hpp"

int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  cout << min(n * a, min(n / m * b + n % m * a, n / m * b + b)) << endl;
}
