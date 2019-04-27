#include "vector.hpp"

int main() {
  int64_t a, b, c;
  cin >> a >> b >> c;
  cout << min({a % 2 * b * c, b % 2 * a * c, c % 2 * a * b}) << endl;
}
