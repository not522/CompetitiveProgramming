#include "template.hpp"

int main() {
  int k[4], d, res = 0;
  for (int& i : k) cin >> i;
  cin >> d;
  for (int i = 1; i <= d; ++i) {
    bool unharmed = true;
    for (int j : k) {
      if (i % j == 0) unharmed = false;
    }
    if (!unharmed) ++res;
  }
  cout << res << endl;
}
