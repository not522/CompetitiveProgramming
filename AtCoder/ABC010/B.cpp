#include "template.hpp"

int main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    while (a % 2 == 0 || a % 3 == 2) {
      ++res;
      --a;
    }
  }
  cout << res << endl;
}
