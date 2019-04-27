#include "template.hpp"

int main() {
  int x;
  cin >> x;
  for (int i = 0; ; ++i) {
    if (abs(x) <= i * (i + 1) / 2) {
      cout << i << endl;
      return 0;
    }
  }
}
