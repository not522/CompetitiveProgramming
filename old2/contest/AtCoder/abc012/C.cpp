#include "template.hpp"

int main() {
  int n = 2025 - int(in);
  for (int i = 1; i <= 9; ++i) {
    if (n % i == 0 && n / i <= 9) {
      cout << i << " x " << n / i << endl;
    }
  }
}
