#include "template.hpp"

int main() {
  double p, q;
  cin >> p >> q;
  cout << ((1 - p) * q < p * (1 - q) * q ? "YES" : "NO") << endl;
}
