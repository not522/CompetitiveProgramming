#include "template.hpp"

int main() {
  int64_t n, k;
  cin >> n >> k;
  cout << 2 * k - (k <= (n + 1) / 2 ? 1 : n + n % 2) << endl;
}
