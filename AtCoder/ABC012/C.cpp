#include "template.hpp"

int main() {
  int n;
  cin >> n;
  n = 2025 - n;
  for (int i = 1; i <= 9; ++i) {
    if (n % i || n / i > 9) continue;
    cout << i << " x " << n / i << endl;
  }
}
