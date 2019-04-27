#include "template.hpp"

int main() {
  int64_t q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  q *= 4;
  h *= 2;
  cout << n / 2 * min({2 * q, 2 * h, 2 * s, d}) + n % 2 * min({q, h, s}) << endl;
}
