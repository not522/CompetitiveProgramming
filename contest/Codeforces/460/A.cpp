#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; ; ++i, --n) {
    if (i && i % m == 0) ++n;
    if (n == 0) {
      cout << i << endl;
      return 0;
    }
  }
}
