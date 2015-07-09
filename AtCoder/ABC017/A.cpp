#include "template.hpp"

int main() {
  int res = 0;
  for (int i = 0; i < 3; ++i) {
    int s, e;
    cin >> s >> e;
    res += s / 10 * e;
  }
  cout << res << endl;
}
