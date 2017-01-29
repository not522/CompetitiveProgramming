#include "template.hpp"

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    if (n % i) continue;
    bool lucky = true;
    for (int j = i; j; j /= 10) {
      if (j % 10 != 4 && j % 10 != 7) {
        lucky = false;
        break;
      }
    }
    if (lucky) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
