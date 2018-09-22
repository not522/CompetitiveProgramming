#include "template.hpp"

int main() {
  int n;
  cin >> n;
  for (int i = 0; 4 * i <= n; ++i) {
    for (int j = 0; 4 * i + 7 * j <= n; ++j) {
      if (4 * i + 7 * j == n) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
